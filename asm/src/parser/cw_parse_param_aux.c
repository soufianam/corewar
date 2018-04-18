/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:38:49 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/18 10:58:27 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.h"
#include "libft.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

static void		cw_init_param(t_instruct *inst, int i)
{
	inst->param[i].pid = 0;
	inst->param[i].val = 0;
	inst->param[i].link = 0;

}

static int		cw_check_reg_legality(int i, t_instruct *inst, char *param)
{
	int		ret;

	if ((ret = ((optab[inst->id].param[i] & T_REG) == T_REG)))
	{
		if (!ft_strisdigit(&(param[1])))
			return (-1);
		inst->param[i].val = ft_atoi(&(param[1]));
		inst->param[i].pid |= T_REG;
		inst->ocp |= (REG_CODE << (6 - (2 * i)));
	}
	return (ret);
}

static int		cw_check_dir_legality(int i, char *param, t_instruct *inst)
{
	int		ret;

	ret = 0;
	if (param[1] == LABEL_CHAR)
	{
		if ((ret = ((param[2] != 0 && ft_strchr(LABEL_CHARS, param[2])))))
			inst->param[i].pid |= T_LAB;
		if (ret > 0)
			inst->param[i].link = ft_strdup(&param[1]);
	}
	if ((ret = ((optab[inst->id].param[i] & T_DIR) == T_DIR)))
	{
		if (ft_strisdigit(&(param[2])))
			inst->param[i].val = ft_atoi(&(param[1]));
		else
			inst->param[i].link = ft_strdup(&param[2]);
		inst->param[i].pid |= T_DIR;
		inst->ocp |= (DIR_CODE << (6 - (2 * i)));
	}
	return (ret);
}

static int		cw_check_ind_legality(int i, char *param, t_instruct *inst)
{
	int		ret;

	if (param[0] == LABEL_CHAR)
	{
		if ((ret = ((param[1] != 0 && ft_strchr(LABEL_CHARS, param[2])))))
			inst->param[i].pid |= T_LAB;
		if (ret > 0)
			inst->param[i].link = ft_strdup(&param[1]);
	}
	else if ((ret = ((optab[inst->id].param[i] & T_IND) == T_IND)))
	{
		if (!ft_strisdigit(&(param[1])))
			return (-1);
		inst->param[i].val = ft_atoi(&(param[1]));
		inst->param[i].pid |= T_IND;
		inst->ocp |= (IND_CODE << (6 - (2 * i)));
	}
	return (ret);
}

extern int		cw_insert_param(char *param, t_instruct **inst, int i)
{
	int		ret;

	ret = 1;
	cw_init_param(*inst, i);
	if (param == 0)
		return (ret);
	ft_strsanitalize(param, " ");
	if (param == 0)
		return (ret);
	if (ret != 0 && param[0] == 'r')
		ret = cw_check_reg_legality(i, *inst, param);
	else if (ret != 0 && param[0] == DIRECT_CHAR)
		ret = cw_check_dir_legality(i, param, *inst);
	else if (ret != 0)
		ret = cw_check_ind_legality(i, param, *inst);
	return (ret);
}
