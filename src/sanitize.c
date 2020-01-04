/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 05:40:10 by jochang           #+#    #+#             */
/*   Updated: 2019/09/26 05:40:10 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	remove_comments(char *line)
{
	while (*line && *line != COMMENT_CHAR)
		line++;
	if (*line == COMMENT_CHAR)
		*line = '\0';
}

static void	clean_spaces(char **line)
{
	char	*old;

	old = *line;
	*line = ft_strtrim(*line);
	free(old);
}

void		sanitize(char **line)
{
	remove_comments(*line);
	clean_spaces(line);
}
