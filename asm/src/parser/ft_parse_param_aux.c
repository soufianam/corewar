/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:38:49 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/12 17:27:31 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.h"
#include "libft.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

void		ft_init_param(t_instruct *inst, int i)
{
	inst->param[i].pid = 0;
	inst->param[i].val = 0;
	inst->param[i].link = 0;

}

int			ft_check_reg_legality(int i, t_instruct *inst)
{
	int		ret;

	if ((ret = optab[inst->id].param[i] & T_REG))
		inst->param[i].val |= T_REG;
	return (ret);
}

int			ft_check_label_legality(int i, char *param, t_instruct *inst)
{
	int		ret;

	ret = 0;
	if (param[1] == ':')
	{
		if ((ret = optab[inst->id].param[i] & T_LAB))
			inst->param[i].val |= T_LAB;
	}
	if ((ret = (ret | (optab[inst->id].param[i] & T_DIR))))
		inst->param[i].val |= T_DIR;
	return (ret);
}

int			ft_check_dir_legality(int i, char *param, t_instruct *inst)
{
	int		ret;

	if (param[0] == ':')
	{
		if ((ret = optab[inst->id].param[i]) & T_LAB)
			inst->param[i].val |= T_LAB;
	}
	else
	{
		if ((ret = optab[inst->id].param[i] & T_IND))
			inst->param[i].val |= T_IND;
	}
	return (ret);
}

int			ft_insert_param(char *param, t_instruct **inst, int i)
{
	int		ret;

	ret = 1;
	ft_init_param(*inst, i);
	if (param == 0)
		return (ret);
	ft_strsanitalize(param, " ");
	if (param == 0)
		return (ret);
	if (param[0] == 'r')
		ret = ft_check_reg_legality(i, *inst);
	else if (param[0] == '%')
		ret = ft_check_label_legality(i, param, *inst);
	else
		ret = ft_check_dir_legality(i, param, *inst);
	if (ret > 0)
		(*inst)->param[i].link = ft_strdup(param);
	return (ret);
}
