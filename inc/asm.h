/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:57:56 by jochang           #+#    #+#             */
/*   Updated: 2019/09/21 21:57:57 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"

#include "op.h"

/*
** Enums
*/
typedef enum	e_state
{
	LABEL,
	INSTRUCTION,
	WHITESPACE,
	REGISTER,
	SEPARATOR
}				t_state;

/*
** Structs
*/
typedef struct	s_table
{
	uint32_t	prog_size;
	char		prog_name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
}				t_table;

typedef struct	s_token
{
	t_state		state;
	char		*content;
}				t_token;

/*
** Functions
*/
void	assembler(char* file);
int		get_header(t_table *table, int fd);
int		get_bytecode(t_table *table, int fd);

/*
** Utility
*/
int		valid_extension(char *file, char *ext);

#endif
