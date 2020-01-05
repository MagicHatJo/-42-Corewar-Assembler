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
			if (!parser(line, &token))
				return (0);
		if (*cmd != 0 && !populate_table(table, line))
			return (0);
		i++;
		free(cmd);
	}
	return (1);
}
