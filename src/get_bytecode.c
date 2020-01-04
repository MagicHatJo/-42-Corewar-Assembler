/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bytecode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:54:59 by jochang           #+#    #+#             */
/*   Updated: 2019/09/23 21:55:00 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static uint8_t	encoding_byte(t_line *line)
{
	int		i;
	uint8_t	encode;

	i = -1;
	while (++i < line->argc)
	{
		if (line->param_type[i] == T_REG)
			encode = REG_CODE;
		else if (line->param_type[i] == T_DIR)
			encode = DIR_CODE;
		else if (line->param_type[i] == T_IND)
			encode = IND_CODE;
		else
			return (return_error("Invalid encoding byte"));
		line->acb |= encode << (6 - (2 * i));
	}
	return (1);
}

static uint8_t	expected_byte_count(t_line *line)
{
	int		count;
	int		i;

	count = 0;
	if (line->cmd >= 0 && line->cmd < 16)
		count++;
	if (g_op_tab[line->cmd].acb)
		count++;
	i = -1;
	while (++i < line->argc)
	{	
		if (line->param_type[i] == T_REG)
			count++;
		else if (line->param_type[i] == T_DIR)
			count += (g_op_tab[line->cmd].half_size ? 2 : 4);
		else if (line->param_type[i] == T_IND)
			count += 2;
	}
	return (count);
}

static int	validate_line(t_line *line)
{
	int		i;

	if (line->argc != g_op_tab[line->cmd].argc)
		return (return_error2(	"Too many arguments on at command >>",
								g_op_tab[line->cmd].name));
	i = -1;
	while (++i < line->argc)
		if (!(line->param_type[i] & g_op_tab[line->cmd].types[i]))
			return (return_error2(	"Invalid argument types for command >>",
									g_op_tab[line->cmd].name));
	return (1);
}

static void	add_label(t_table *table, t_line *line)
{
	t_lookup *node;

	node = ft_memalloc(sizeof(t_lookup));
	node->label = ft_strdup(line->label);
	node->value = line->prior_data;
	deque_push_back(table->labels, node);
}

int	get_bytecode(t_table *table, int fd)
{
	char	*cmd;
	t_token	token;
	t_line	*line;
	int		i;

	i = 1;
	while (get_next_line(fd, &cmd))
	{
		line = ft_memalloc(sizeof(t_line));
		line->line_number = i;
		line->prior_data = table->prog_size;
		sanitize(&cmd);
		while ((token = lexer(cmd)).state != NONE)
			ZERO_CHECK(!parser(line, &token));
		if (*cmd != 0)
		{
			ZERO_CHECK(!(encoding_byte(line)));
			table->prog_size += expected_byte_count(line);
			ZERO_CHECK(!validate_line(line));
			deque_push_back(table->commands, line);
			if (line->label)
				add_label(table, line);
		}
		i++;
		free(cmd);
	}
	return (1);
}
