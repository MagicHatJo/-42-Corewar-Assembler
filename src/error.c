/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eerror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:47:26 by jochang           #+#    #+#             */
/*   Updated: 2019/09/21 22:47:27 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	return_error(char message[])
{
	ft_printf("\033[31mError:\033[0m %s\n", message);
	return (0);
}

int	return_error2(char m1[], char m2[])
{
	ft_printf("\033[31mError:\033[0m %s %s\n", m1, m2);
	return (0);
}