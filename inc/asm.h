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
#include "libfd.h"

#include "op.h"

#include <fcntl.h>

/*
** Enums
*/
typedef enum	e_state
{
	NONE,
	LABEL,
	INSTRUCTION,
	PARAMETER
}				t_state;

/*
** Structs
*/
typedef struct	s_table
{
	uint64_t	prog_size;
	char		prog_name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];

	t_deque		*commands;//stores lines
	t_deque		*labels;//stores labels
}				t_table;

typedef struct	s_lookup
{
	char		*label;
	uint32_t	value;
}				t_lookup;

typedef struct	s_token
{
	t_state		state;
	char		*content;
}				t_token;

typedef struct	s_line
{
	int			line_number;
	char		*label;
	uint8_t		cmd;
	uint8_t		acb; // encoding byte
	//access each parameter as an int, and cast accordingly later when writing
	uint8_t		param_type[MAX_ARGS_NUMBER];//parameter type (register, direct, indirect)
	uint32_t	parameters[MAX_ARGS_NUMBER];//parameters
	//array of char*, hold labels. if they are not empty when i sweep through for labels,
	//fill the corrosponding parameter with the result i calculate using said label and current data size
	char		*param_label[MAX_ARGS_NUMBER];
	uint8_t		argc;	//for use with comparing against number of required arguments
	uint64_t	prior_data;	//amount of bytes existing before this command
}				t_line;

typedef struct	s_op
{
	char		*name;
	int			argc;
	int			types[4];
	int			code;
	int			cycles;
	char		*desc;
	int			acb;
	int			half_size;
}				t_op;

/*
** Globals
*/
extern const t_op	g_op_tab[17];

/*
** Functions
*/
int		assembler(char* file);
int		get_header(t_table *table, int fd);
int		get_bytecode(t_table *table, int fd);
t_token	lexer(char* cmd);
int		parser(t_line *line, t_token *token);
int		parse_parameter(t_line *line, char *cmd);
uint8_t	process_labels(t_table *table);
void	make_cor(char *file, t_table *table);
/*
** Utility
*/
int		valid_extension(char *file, char *ext);
int		valid_number(char *cmd);
void	sanitize(char **line);
int		return_error(char message[]);
int		return_error2(char m1[], char m2[]);

#endif
