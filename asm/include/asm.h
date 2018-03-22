/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:09:49 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/22 18:45:57 by pprikazs         ###   ########.fr       */
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
	TRUE = 0
}				t_bool;

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
	char	pid;
	int		val;
	char	*link;
}				t_param;

typedef struct	s_instruct
{
	char	*label;
	int		pc;
	char	id;
	char	ocp;
	t_param	param[3];
}				t_instruct;

#endif
