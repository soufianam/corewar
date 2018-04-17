/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_update_pc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:12:15 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/17 17:26:50 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/cdefs.h>
#include "op.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

static int		cw_parse_get_dirsize(int id)
{
	if (id == 0 || id == 1 || id == 5 || id == 6 || id == 7 || id == 12)
		return (4);
	else
		return (2);
}

static void		cw_parse_calculate_pc(t_instruct **ins, t_instruct *last)
{
	int			pc;
	int			i;

	pc = last->pc;
	pc++;
	if (optab[last->id].codage == TRUE)
	{
		pc++;
		i = 0;
		while (i < 3)
		{
			if (((int)last->ocp >> (6 - (i * 2)) & IND_CODE) == IND_CODE)
				pc += 2;
			else if (((int)last->ocp >> (6 - (i * 2)) & REG_CODE) == REG_CODE)
				pc += 1;
			else if (((int)last->ocp >> (6 - (i * 2)) & DIR_CODE) == DIR_CODE)
				pc += cw_parse_get_dirsize(last->id);
			i++;
		}
	}
	else
		pc += cw_parse_get_dirsize(last->id);
	(*ins)->pc = pc;
}

extern void		cw_parse_update_pc(t_instruct **ins, t_list **list)
{
	t_list		*last;

	if (*list == 0)
		(*ins)->pc = 0;
	else
	{
		last = ft_lstlast(list);
		cw_parse_calculate_pc(ins, (t_instruct *)last->content);
	}
}
