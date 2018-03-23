/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:50:32 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/23 18:55:45 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "ft_printf.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

void			ft_display_optab(void)
{
	int			i;

	i = 0;
	while (i < OP_TAB_SIZE)
	{
		ft_printf("ins : %s | nb_param : %d | ", optab[i].ins, optab[i].nb_param);
		ft_printf("params : {p1 %d , p2 %d, ", optab[i].param[0], optab[i].param[1]);
		ft_printf("p3 %d, p4 %d} | ", optab[i].param[2], optab[i].param[3]);
		ft_printf("opcode : %d | ", optab[i].opcode);
		ft_printf("nb_cycle : %d | ", optab[i].nb_cycle);
		ft_printf("desc : %s | ", optab[i].desc);
		ft_printf("carry : %d | codage : %d \n", optab[i].carry, optab[i].codage);
		i++;
	}
}

int			ft_count_op_param(int8_t id)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (optab[id].param[i] == 0)
			return (i++);
		i++;
	}
	return (++i);
}
