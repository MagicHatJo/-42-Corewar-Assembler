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
#include "queue.h"

#include "op.h"

/*
** Enums
*/
typedef enum	e_state
{
	NONE,
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

	t_queue		*commands;
}				t_table;

typedef struct	s_token
{
	t_state			state;
	char			*content;
}				t_token;

typedef struct	s_line
{
	int		line_number;
	char	*label;
	char	*cmd;

}				t_line;

typedef struct	s_op
{
	char	*name;
	int		argc;
	int		types[4];
	int		code;
	int		cycles;
	char	*desc;
	int		acb;
	int		flag2;
}				t_op;

/*
** Globals
*/
extern const t_op	g_op_tab[17];

/*
** Functions
*/
void	assembler(char* file);
int		get_header(t_table *table, int fd);
int		get_bytecode(t_table *table, int fd);
t_token	lexer(char* cmd);

/*
** Utility
*/
int		valid_extension(char *file, char *ext);
void	sanitize(char **line);

#endif
