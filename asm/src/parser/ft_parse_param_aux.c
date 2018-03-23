/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:38:49 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/23 19:55:52 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.c"
#include "libft.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

void		ft_init_param(t_instruct *ins, int i)
{
	ins->param[i].pid = 0;
	ins->param[i].val = 0;
	ins->param[i].link = 0;

}

int			ft_check_reg_legality(int i, t_instruct *ins)
{
	int		ret;

	if ((ret = optab[ins.id].param[i] & T_REG))
		ins->param[i].val |= T_REG;
	return (ret);
}

int			ft_check_label_legality(int i, char *param, t_instruct *ins)
{
	int		ret;

	if (param[1] == ':')
	{
		if ((ret = optab[ins.id].param[i] & T_LABEL))
			ins->param[i].val |= T_LABEL;
	}
	if ((ret = (ret & (optab[ins.id].param[i] & T_DIR))))
		ins->param[i].val |= T_DIR;
	return (ret);
}

int			ft_check_dir_legality(int i, char *param, t_instruct *ins)
{
	int		ret;

	if (param[0] == ':')
	{
		if((ret = optab[ins.id].param[i] & T_LABEL)
			ins->param[i].val |= T_LABEL;
	}
	else
	{
		if ((ret = optab[ins.id].param[i] & T_IND))
			ins->param[i].val |= T_IND;
	}
	return (ret);
}

int			ft_instert_param(char *param, t_instruct *ins, int i)
{
	int		ret;

	ret = 1;
	ft_init_param(ins, i);
	if (param == 0)
		return (ret);
	if (param[0] == 'r')
		ret = ft_check_reg_legality(i, *ins);
	else if (param[0] == '%')
		ret = ft_check_label_legality(i, param, *ins);
	else
		ret = ft_check_dir_legality(i, *ins);
	if (ret == 1)
		ins->param[i]-> = ft_strdup(param);
	return (ret);
}
