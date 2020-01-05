/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:13:22 by jochang           #+#    #+#             */
/*   Updated: 2019/09/21 22:13:23 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	valid_extension(char *file, char *ext)
{
	int	len;

	len = ft_strlen(file) - ft_strlen(ext) - 1;
	if (len <= 0 || file[len] != '.')
		return (0);
	return (ft_strequ(&file[len + 1], ext));
}
