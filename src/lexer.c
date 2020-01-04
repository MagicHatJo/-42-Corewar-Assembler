/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 06:40:20 by jochang           #+#    #+#             */
/*   Updated: 2019/09/26 06:40:21 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		is_label(char *cmd)
{
	while (*cmd)
		cmd++;
	return (*(--cmd) == ':' ? 1 : 0);
}

static int		is_instruction(char *cmd)
{
	int		i;

	i = -1;
	while (g_op_tab[++i].name)
		if (ft_strequ(cmd, g_op_tab[i].name))
			return (1);
	return (0);
}

static t_state	token_state(char *cmd)
{
	if (*cmd == '\0')
		return (NONE);
	if (is_label(cmd))
		return (LABEL);
	if (is_instruction(cmd))
		return (INSTRUCTION);
	return (PARAMETER);
}

static void		fix_label(char **label)
{
	char*	new_content;

	new_content = ft_strcdup(*label, ':');
	free(*label);
	*label = new_content;
}

t_token			lexer(char* cmd)
{
	static int	i;
	t_token		token;

	while (cmd[i] && (ft_isspace(cmd[i]) || cmd[i] == SEPARATOR_CHAR))
		i++;
	token.content = ft_strtok(&cmd[i], "\f\t \n\v\r,");
	while (cmd[i] && !ft_isspace(cmd[i]) && cmd[i] != SEPARATOR_CHAR)
		i++;
	token.state = token_state(token.content);
	if (token.state == LABEL)
		fix_label(&token.content);
	if (token.state == NONE)
		i = 0;
	return (token);
}
