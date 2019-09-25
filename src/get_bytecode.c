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
	char	*line;

	(void)table;
	while (get_next_line(fd, &line))
	{
		ft_printf("%s\n", line);

		//lexer - tokenize line. if there is a ;, end current line parsing after it
		//	strsplit and throw out everything after ;
		//parser
		//store into t_byte


		free(line);
	}
	return (1);
}
