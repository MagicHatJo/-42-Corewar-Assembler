/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:47:26 by jochang           #+#    #+#             */
/*   Updated: 2019/09/21 22:47:27 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	valid_program_size(t_table *table)
{
	return (table->prog_size > CHAMP_MAX_SIZE ? 0 : 1);
}

static void	cleanup(t_table *table)
{
	t_line		*line_node;
	t_lookup	*lookup_node;
	int			i;

	while (!deque_empty(table->commands))
	{
		line_node = deque_pop_front(table->commands);
		free(line_node->label);
		i = -1;
		while (++i < line_node->argc)
			if (line_node->param_label[i])
				free(line_node->param_label[i]);
		free(line_node);
	}
	while (!deque_empty(table->labels))
	{
		lookup_node = deque_pop_front(table->labels);
		free(lookup_node->label);
		free(lookup_node);
	}
	free(table->commands);
	free(table->labels);
}

int			assembler(char *file)
{
	int		fd;
	t_table	table;

	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, &fd, 0) < 0)
		return (return_error2(file, "not found"));
	ft_memset(&table, 0, sizeof(t_table));
	table.commands = deque_init();
	table.labels = deque_init();
	if (get_header(&table, fd) && get_bytecode(&table, fd))
	{
		if (valid_program_size(&table))
		{
			process_labels(&table);
			make_cor(file, &table);
			ft_printf("\033[32mCompiled:\033[0m %s\n", file);
		}
		else
			ft_printf("\033[31mError:\033[0m %s\n", "Program too large");
	}
	else
		ft_printf("\033[31mError:\033[0m %s %s\n", "Invalid file :", file);
	close(fd);
	cleanup(&table);
	return (0);
}
