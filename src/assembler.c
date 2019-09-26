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

void	assembler(char *file)
{
	int			fd;
	t_table		table;

	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, &fd, 0) < 0)
	{
		ft_printf("\033[31mError:\033[0m %s %s\n", "Unable to open", file);
		return ;
	}
	ft_memset(&table, 0, sizeof(t_table));
	table.commands = initqueue();
	if (get_header(&table, fd) && get_bytecode(&table, fd))
	{
		ft_printf("\033[32mCompiled:\033[0m %s\n", file);
		//make .cor
	}
	else
		ft_printf("\033[31mError:\033[0m %s %s\n", "Invalid file :", file);
	close(fd);
}