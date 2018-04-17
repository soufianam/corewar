/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:09:49 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/17 16:38:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <sys/cdefs.h>
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
	t_bool		carry;
	t_bool		codage;
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
	t_param			param[4];
}				t_instruct;

extern t_op		optab[OP_TAB_SIZE];

void			cw_display_optab(void);
int				cw_insert_param(char *param, t_instruct **inst, int i);
int				cw_parse(char *file, t_list **instruct);
int				cw_parse_instruct(char *instruct, t_instruct **inst, char ***param);
int				cw_parse_label(char *line, t_instruct **inst, char ***lab);
int				cw_parse_param(t_instruct **ins, char **param);
void			cw_parse_update_pc(t_instruct **ins, t_list **list);
void			cw_display_instruct(t_list *elem);

#endif
