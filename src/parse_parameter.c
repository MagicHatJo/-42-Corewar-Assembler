/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:54:59 by jochang           #+#    #+#             */
/*   Updated: 2019/09/23 21:55:00 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	parse_register(t_line *line, char *cmd)
{
	line->param_type[line->argc] = T_REG;
	if (!valid_number(++cmd))
		return (return_error("Invalid register"));
	line->parameters[line->argc] = ft_atoi(cmd);
	if (line->parameters[line->argc] < 0 ||
		line->parameters[line->argc] > REG_NUMBER)
		return (return_error("Invalid register"));
	line->argc++;
	return (1);
}

static int	parse_direct(t_line *line, char *cmd)
{
	line->param_type[line->argc] = T_DIR;
	if (*(cmd + 1) == ':')
		line->param_label[line->argc] = ft_strdup(cmd + 2);
	else
	{
		if (!valid_number(++cmd))
			return (return_error("Invalid direct"));
		line->parameters[line->argc] = ft_atoi(cmd);
	}
	line->argc++;
	return (1);
}

static int	parse_indirect(t_line *line, char *cmd)
{
	line->param_type[line->argc] = T_IND;
	if (*cmd == ':')
		line->param_label[line->argc] = ft_strdup(cmd + 1);
	else
	{
		if (!valid_number(cmd))
			return (return_error("Invalid indirect"));
		line->parameters[line->argc] = ft_atoi(cmd);
	}
	line->argc++;
	return (1);
}

int	parse_parameter(t_line *line, char *cmd)
{
	if (*cmd == 0)
		return (1);
	if (*cmd == 'r')
		return (parse_register(line, cmd));
	else if (*cmd == DIRECT_CHAR)
		return (parse_direct(line, cmd));
	return (parse_indirect(line, cmd));
}