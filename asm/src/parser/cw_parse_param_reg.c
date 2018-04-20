/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_param_reg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:46:50 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/20 17:51:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.h"
#include "libft.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

extern int		cw_parse_param_reg(int i, t_instruct *inst, char *param)
{
	int		ret;

	if ((ret = ((optab[inst->id].param[i] & T_REG) == T_REG)))
	{
		if (param[1] == 0)
			return (-1); //Flag registre définit mais rien ne suit;
		if (!ft_strisdigit(&(param[1])))
			return (-1); //Erreur définition de registre
		inst->param[i].val = ft_atoi(&(param[1]));
		inst->param[i].pid |= T_REG;
		inst->ocp |= (REG_CODE << (6 - (2 * i)));
	}
	else
		ret = -1; //Erreur le paramettre n'attends pas de registe à cet emplacement
	return (ret);
}
