/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 22:47:26 by jochang           #+#    #+#             */
/*   Updated: 2019/09/21 22:47:27 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write8(uint8_t *ptr, uint32_t *offset, uint8_t n)
{
	ft_memcpy(ptr + (*offset), &n, 1);
	*offset += 1;
}

void	write16(uint8_t *ptr, uint32_t *offset, uint16_t n)
{
	ft_memcpy(ptr + (*offset), &n, 2);
	*offset += 2;
}

void	write32(uint8_t *ptr, uint32_t *offset, uint32_t n)
{
	ft_memcpy(ptr + (*offset), &n, 4);
	*offset += 4;
}

void	write_parameters(uint8_t *ptr, uint32_t *offset, t_line *line)
{
	int			i;
	uint8_t		one;
	uint16_t	two;
	uint32_t	four;

	i = -1;
	while (++i < line->argc)
	{
		if (line->param_type[i] == T_REG)
			write8(ptr, offset, (uint8_t)line->parameters[i]);
		else if (line->param_type[i] == T_DIR)
		{
			if (g_op_tab[line->cmd].half_size)
				write16(ptr, offset,
					ft_swapendian16((uint16_t)(line->parameters[i])));
			else
				write32(ptr, offset,
					ft_swapendian32(line->parameters[i]));
		}
		else if (line->param_type[i] == T_IND)
			write16(ptr, offset,
				ft_swapendian16((uint16_t)(line->parameters[i])));
	}
}
