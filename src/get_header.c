/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 23:47:41 by jochang           #+#    #+#             */
/*   Updated: 2019/09/21 23:47:41 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_name(char prog_name[], int fd)
{
	char	*line;
	char	*dq;
	int		i;

	
	ZERO_CHECK(!get_next_line(fd, &line));
	ZERO_CHECK(!ft_strnequ(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)));
	ZERO_CHECK(!(dq = ft_strchr(line, '"')));
	dq++;
	i = -1;
	while (dq[++i] && dq[i] != '"' && i < PROG_NAME_LENGTH)
		prog_name[i] = dq[i];
	ZERO_CHECK(dq[i] != '"');
	free(line);
	return (1);
}

static int	get_comment(char comment[], int fd)
{
	char	*line;
	char	*dq;
	int		i;

	ZERO_CHECK(!get_next_line(fd, &line));
	if (!ft_strnequ(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		return (0);
	ZERO_CHECK(!(dq = ft_strchr(line, '"')));
	dq++;
	i = -1;
	while (dq[++i] && dq[i] != '"' && i < COMMENT_LENGTH)
		comment[i] = dq[i];
	ZERO_CHECK(dq[i] != '"');
	free(line);
	return (1);
}

int			get_header(t_table *table, int fd)
{
	ZERO_CHECK(!get_name(table->prog_name, fd));
	ZERO_CHECK(!(get_comment(table->comment, fd)));
	return (1);
}
