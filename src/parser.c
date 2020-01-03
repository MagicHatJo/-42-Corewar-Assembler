/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:54:59 by jochang           #+#    #+#             */
/*   Updated: 2019/09/23 21:55:00 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_instruction(char *cmd)
{
	int	i;

	i = -1;
	while (g_op_tab[++i].argc)
	{
		if (ft_strequ(cmd, g_op_tab[i].name))
			return (i);
	}
	return (16);//sends it to null error. unsure if needs to be changed
}

int			parser(t_line *line, t_token *token)
{
	static int		current_line;
	static t_state	prev_state;

	if (current_line != line->line_number)
	{
		current_line = line->line_number;
		prev_state = NONE;
	}
	if (token->state == LABEL && token->state > prev_state)
		line->label = token->content;
	else if (token->state == INSTRUCTION && token->state > prev_state)
		line->cmd = parse_instruction(token->content);
	else if (token->state == PARAMETER && token->state >= prev_state)
	{
		if (!(parse_parameter(line, token->content)))
			return (0);
	}
	else
		return (0);
	prev_state = token->state;
	return (1);
}