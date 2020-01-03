/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:47:26 by jochang           #+#    #+#             */
/*   Updated: 2019/09/21 22:47:27 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	create_file(char *file)
{
	char	name[1024];

	ft_bzero(name, 1024);
	ft_memcpy(name, file, ft_strlen(file) - 1);
	ft_strcat(name, "cor");
	return (open(name, O_WRONLY | O_CREAT | O_TRUNC));
}

/*
** Header is comprised of 4 parts
** 4 bytes of COREWAR_EXEC_MAGIC
** PROG_NAME_LENGTH bytes of name
** 8 bytes of total byte size of the code portion
** COMMENT_LENGTH bytes of comment
*/
static int	write_header(int fd, char *name, uint64_t total, char *comment)
{
	uint32_t	magic;

	magic = ft_swapendian(COREWAR_EXEC_MAGIC);
	write(fd, &magic, 4);
	write(fd, name, PROG_NAME_LENGTH);
	total = ft_swapendian64(total);
	write(fd, &total, 8);
	write(fd, comment, COMMENT_LENGTH - 4);
	return (1);
}

static int	write_cmd_acb(uint8_t *ptr, uint32_t *offset, t_line *line)
{
	uint16_t value;

	value = g_op_tab[line->cmd].code;
	if (g_op_tab[line->cmd].acb)
		value |= line->acb << 8;
	ft_memcpy(ptr + (*offset), &value, 1 + g_op_tab[line->cmd].acb);
	(*offset) += 1 + g_op_tab[line->cmd].acb;
	return (1);
}

static int	write_parameters(uint8_t *ptr, uint32_t *offset, t_line *line)
{
	int			i;
	uint8_t		one;
	uint16_t	two;
	uint32_t	four;

	i = -1;
	while (++i < line->argc)
	{
		if (line->param_type[i] == T_REG)
		{
			one = (uint8_t)line->parameters[i];
			ft_memcpy(ptr + (*offset), &one, 1);
			(*offset) += 1;
		}
		else if (line->param_type[i] == T_DIR)
		{
			if (g_op_tab[line->cmd].half_size)
			{
				two = (uint16_t)(line->parameters[i]);
				two = END16(two);
				ft_memcpy(ptr + (*offset), &two, 2);
				(*offset) += 2;
			}
			else
			{
				four = (uint32_t)(line->parameters[i]);
				four = ft_swapendian(four);
				ft_memcpy(ptr + (*offset), &four, 4);
				(*offset) += 4;
			}
		}
		else if (line->param_type[i] == T_IND)
		{
			two = (uint16_t)(line->parameters[i]);
			two = END16(two);
			ft_memcpy(ptr + (*offset), &two, 2);
			(*offset) += 2;
		}
	}
	return (1);
}

void	make_cor(char *file, t_table *table)
{
	int			fd;
	int			i;
	t_node		*node;
	uint8_t		*buf;
	uint32_t	offset;

	buf = ft_memalloc(table->prog_size + 1);//unsure if +1 needed
	offset = 0;
	fd = create_file(file);
	write_header(fd, table->prog_name, table->prog_size, table->comment);
	i = -1;
	node = deque_begin(table->commands);
	while (++i < table->commands->size)
	{
		write_cmd_acb(buf, &offset, ((t_line*)(node->content)));
		write_parameters(buf, &offset, ((t_line*)(node->content))); // write parameters
		node = node->next;
	}
	write(fd, buf, table->prog_size);
	free(buf);
	close(fd);
}