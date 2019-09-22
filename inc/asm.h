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
** Structs
*/
typedef struct	s_header
{
	uint32_t	prog_size;
	char		prog_name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
}				t_header;

/*
** Functions
*/
void	assembler(char* file);
int		get_header(t_header *h, int fd);

/*
** Utility
*/
int		valid_extension(char *file, char *ext);

#endif
