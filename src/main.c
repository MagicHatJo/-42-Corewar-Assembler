/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:57:36 by jochang           #+#    #+#             */
/*   Updated: 2019/09/21 21:57:37 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
	{
		ft_printf("\033[33mUsage:\t\033[0m%s\n", "./asm [champion_name].s");
		ft_printf("\tCompiles champion.s files to .cor binary files.\n");
		return (0);
	}
	while (++i < ac)
	{
		if (valid_extension(av[i], "s"))
			ft_printf("Valid Extension\n");//assembler(av[i]);
		else if (valid_extension(av[i], "cor"))
			ft_printf("Disassembler not implemented\n");
		else
			ft_printf("\033[31mError:\033[0m %s is not a valid file\n", av[i]);
	}
	return (0);
}
