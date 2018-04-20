/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_param_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:38:24 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/20 17:51:12 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.h"
#include "libft.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

static int		cw_parse_param_dir_aux(int i, char *param, \
		t_instruct *inst, int *pos)
{
	int			ret;

	ret = 1;
	if (param[*pos] == 0)
		ret = -1; //flag direct definit mais rien ne suit
	else if (param[*pos] == LABEL_CHAR)
	{
		ret = cw_parse_param_lab(i, &param[*pos], inst);	//Erreur de la définition du paramettre indirect
		(*pos)++;
	}
	return (ret);
}

extern int		cw_parse_param_dir(int i, char *param, t_instruct *inst)
{
	int			ret;
	int			pos;

	ret = 1;
	pos = 1;
	if ((ret = ((optab[inst->id].param[i] & T_DIR) == T_DIR)))
	{
		inst->ocp |= (DIR_CODE << (6 - (2 * i)));
		if ((ret = cw_parse_param_dir_aux(i, param, inst, &pos)) < 0)
			return (ret); //Erreur dans les phase de vérifications
		if ((inst->param[i].pid & T_LAB) == 0 && !ft_strisdigit(&(param[pos])))
			return (-1); //Erreur de définition de paramettre indirect
		else if ((inst->param[i].pid & T_LAB) == 0 && ft_strisdigit(&(param[pos])))
			inst->param[i].val = ft_atoi(&(param[pos]));
		inst->param[i].pid |= T_DIR;
	}
	else
		ret = -1; //Erreur le paramettre n'attends pas de paramettre ind à cet emplacement
	return (ret);
}

