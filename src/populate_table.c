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

static int		validate_line(t_line *line)
{
	int		i;

	if (line->argc != g_op_tab[line->cmd].argc)
	{
		return (return_error2("Too many arguments on at command >>",
			g_op_tab[line->cmd].name));
	}
	i = -1;
	while (++i < line->argc)
		if (!(line->param_type[i] & g_op_tab[line->cmd].types[i]))
		{
			return (return_error2("Invalid argument types for command >>",
				g_op_tab[line->cmd].name));
		}
	return (1);
}

static void		add_label(t_table *table, t_line *line)
{
	t_lookup *node;

	node = ft_memalloc(sizeof(t_lookup));
	node->label = ft_strdup(line->label);
	node->value = line->prior_data;
	deque_push_back(table->labels, node);
}

int				populate_table(t_table *table, t_line *line)
{
	if (!(encoding_byte(line)))
		return (0);
	table->prog_size += expected_byte_count(line);
	if (!validate_line(line))
		return (0);
	deque_push_back(table->commands, line);
	if (line->label)
		add_label(table, line);
	return (1);
}
