/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:09:49 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/20 17:50:47 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <sys/cdefs.h>
# include <fcntl.h>
# include "libft.h"
# include "op.h"

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = 1
}				t_bool;

# define OP_TAB_SIZE 17

typedef struct	s_op
{
	char		*ins;
	int8_t		nb_param;
	int8_t		param[4];
	int8_t		opcode;
	int			nb_cycle;
	char		*desc;
	t_bool		codage;
	t_bool		carry;
}				t_op;

typedef struct	s_param
{
	unsigned char	pid;
	int				val;
	char			*link;
}				t_param;

typedef struct	s_instruct
{
	char			*label;
	int				pc;
	int8_t			id;
	unsigned char	ocp;
	int				line;
	t_param			param[4];
}				t_instruct;

extern t_op		optab[OP_TAB_SIZE];

void			cw_display_optab(void);
void			cw_display_header(header_t header);
void			cw_display_instruct(t_list *elem);
void			cw_error(int err_code, t_list *last);
int				cw_parse(char *file, t_list **instruct, header_t *head);
void			cw_parse_comment(char *line);
int				cw_parse_header(char *line, header_t *head);
int				cw_parse_instruct(char *instruct, t_instruct **inst, char ***param);
int				cw_parse_label(char *line, t_instruct **inst, char ***lab);
int				cw_parse_param(t_instruct **ins, char **param);
int				cw_parse_param_dir(int i, char *param, t_instruct *inst);
int				cw_parse_param_ind(int i, char *param, t_instruct *inst);
int				cw_parse_param_lab(int i, char *param, t_instruct *inst);
int				cw_parse_param_reg(int i, t_instruct *inst, char *param);
void			cw_parse_update_pc(t_instruct **ins, t_list **list);

/*
** fct max
*/
int				cw_prog_init(t_list *list, char **bin);
int				cw_check_duplicates_label(t_list *list);
int				cw_label_init(t_list *list);
int				cw_prog_builder(t_list *list, char **bin);

int				cw_write(char *name, header_t head, char *bin);

#endif
