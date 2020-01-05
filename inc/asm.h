/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:57:56 by jochang           #+#    #+#             */
/*   Updated: 2020/01/05 12:40:09 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "libfd.h"

# include "op.h"

# include <fcntl.h>

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
	t_deque		*commands;
	t_deque		*labels;
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

/*
** line:
** line_number : current line number
** label       : label name if applicable, NULL otherwise
** cmd         : command index for g_op_tab
** acb         : argument encding byte if applicable
** param_type  : parameter type (register, direct, indirect)
** parameters  : parameter data
** param_label : holds registered label names for future tracking if found
** argc        : number of arguments found
** prior_data  : total byte count at beginning of this command
*/
typedef struct	s_line
{
	int			line_number;
	char		*label;
	uint8_t		cmd;
	uint8_t		acb;
	uint8_t		param_type[MAX_ARGS_NUMBER];
	uint32_t	parameters[MAX_ARGS_NUMBER];
	char		*param_label[MAX_ARGS_NUMBER];
	uint8_t		argc;
	uint64_t	prior_data;
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
int				assembler(char *file);
int				get_header(t_table *table, int fd);
int				get_bytecode(t_table *table, int fd);
t_token			lexer(char *cmd);
int				parser(t_line *line, t_token *token);
int				parse_parameter(t_line *line, char *cmd);
uint8_t			process_labels(t_table *table);
void			make_cor(char *file, t_table *table);
void			write_parameters(uint8_t *ptr, uint32_t *offset, t_line *line);
int				populate_table(t_table *table, t_line *line);

/*
** Utility
*/
int				valid_extension(char *file, char *ext);
int				valid_number(char *cmd);
void			sanitize(char **line);
int				return_error(char message[]);
int				return_error2(char m1[], char m2[]);

#endif
