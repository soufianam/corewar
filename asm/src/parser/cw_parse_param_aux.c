/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:38:49 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/20 17:25:22 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.h"
#include "libft.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];


static int		cw_check_lab_legality(int i, char *param, t_instruct *inst)
{
	if (param[1] == 0)
		return (-1); //flag label definit mais rien ne suit
	else if (!ft_strchr(LABEL_CHARS, param[1])) // !IMPORTANT à remplacer sur l'authenticité complete de la chaine
		return (-1); //Erreur de définition de label
	inst->param[i].link = ft_strdup(&param[1]);
	inst->param[i].pid |= (T_LAB);
	return (1);
}

static int		cw_check_ind_legality_aux(int i, char *param, t_instruct *inst, int *pos)
{
	int		ret;

	ret = 1;
	if (param[*pos] == LABEL_CHAR)
	{
		ret = cw_check_lab_legality(i, &param[*pos], inst);	//Erreur de la définition du paramettre indirect
		(*pos)++;
	}
	return (ret);
}

static int		cw_check_ind_legality(int i, char *param, t_instruct *inst)
{
	int		ret;
	int		pos;

	ret = 1;
	pos = 0;
	if ((ret = ((optab[inst->id].param[i] & T_IND) == T_IND)))
	{
		inst->ocp |= (IND_CODE << (6 - (2 * i)));
		if ((ret = cw_check_ind_legality_aux(i, param, inst, &pos)) < 0)
			return (ret); //Erreur dans les phase de vérifications
		if ((inst->param[i].pid & T_LAB) == 0 && !ft_strisdigit(&(param[pos])))
			return (-1); //Erreur de définition de paramettre indirect
		else if ((inst->param[i].pid & T_LAB) == 0 && ft_strisdigit(&(param[pos])))
			inst->param[i].val = ft_atoi(&(param[pos]));
		inst->param[i].pid |= T_IND;
	}
	else
		ret = -1; //Erreur le paramettre n'attends pas de paramettre ind à cet emplacement
	return (ret);

}

static int		cw_check_dir_legality_aux(int i, char *param, t_instruct *inst, int *pos)
{
	int		ret;

	ret = 1;
	if (param[*pos] == 0)
		ret = -1; //flag direct definit mais rien ne suit
	else if (param[*pos] == LABEL_CHAR)
	{
		ret = cw_check_lab_legality(i, &param[*pos], inst);	//Erreur de la définition du paramettre indirect
		(*pos)++;
	}
	return (ret);
}

static int		cw_check_dir_legality(int i, char *param, t_instruct *inst)
{
	int		ret;
	int		pos;

	ret = 1;
	pos = 1;
	if ((ret = ((optab[inst->id].param[i] & T_DIR) == T_DIR)))
	{
		inst->ocp |= (DIR_CODE << (6 - (2 * i)));
		if ((ret = cw_check_dir_legality_aux(i, param, inst, &pos)) < 0)
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

static int		cw_check_reg_legality(int i, t_instruct *inst, char *param)
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

extern int		cw_insert_param(char *param, t_instruct **inst, int i)
{
	int		ret;

	ret = 1;
	if (param != 0)
		ft_strsanitalize(param, " ");
	if (param == 0)
		return (ret); //Potentiel car d'erreur non traité pour le moment (nombre de param inférieur à l'instruction
	if (ret > 0 && param[0] == 'r')
		ret = cw_check_reg_legality(i, *inst, param);
	else if (ret > 0 && param[0] == DIRECT_CHAR)
		ret = cw_check_dir_legality(i, param, *inst);
	else if (ret > 0)
		ret = cw_check_ind_legality(i, param, *inst);
	return (ret);
}
