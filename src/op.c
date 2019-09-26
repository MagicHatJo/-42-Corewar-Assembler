/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2019/03/20 02:52:55 by jtashako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define TYPE0 {0}
#define TYPE1 {T_DIR}
#define TYPE2 {T_DIR | T_IND, T_REG}
#define TYPE3 {T_REG, T_IND | T_REG}
#define TYPE4 {T_REG, T_REG, T_REG}
#define TYPE5 {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}
#define TYPE6 {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
#define TYPE7 {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}
#define TYPE8 {T_REG}

const t_op	g_op_tab[17] =
{
	{"live", 1, TYPE1, 1, 10, "alive", 0, 0},
	{"ld", 2, TYPE2, 2, 5, "load", 1, 0},
	{"st", 2, TYPE3, 3, 5, "store", 1, 0},
	{"add", 3, TYPE4, 4, 10, "addition", 1, 0},
	{"sub", 3, TYPE4, 5, 10, "subtraction", 1, 0},
	{"and", 3, TYPE5, 6, 6, "and  r1 & r2 -> r3", 1, 0},
	{"or", 3, TYPE5, 7, 6, "or   r1 | r2 -> r3", 1, 0},
	{"xor", 3, TYPE5, 8, 6, "xor  r1 ^ r2 -> r3", 1, 0},
	{"zjmp", 1, TYPE1, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, TYPE6, 10, 25, "load index", 1, 1},
	{"sti", 3, TYPE7, 11, 25, "store index", 1, 1},
	{"fork", 1, TYPE1, 12, 800, "fork", 0, 1},
	{"lld", 2, TYPE2, 13, 10, "long load", 1, 0},
	{"lldi", 3, TYPE6, 14, 50, "long load index", 1, 1},
	{"lfork", 1, TYPE1, 15, 1000, "long fork", 0, 1},
	{"aff", 1, TYPE8, 16, 2, "ascii to stdout", 1, 0},
	{0, 0, TYPE0, 0, 0, 0, 0, 0}
};
