/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_parse_param_lab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:45:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/20 17:51:21 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.h"
#include "libft.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

extern int		cw_parse_param_lab(int i, char *param, t_instruct *inst)
{
	if (param[1] == 0)
		return (-1); //flag label definit mais rien ne suit
	else if (!ft_strchr(LABEL_CHARS, param[1])) // !IMPORTANT à remplacer sur l'authenticité complete de la chaine
		return (-1); //Erreur de définition de label
	inst->param[i].link = ft_strdup(&param[1]);
	inst->param[i].pid |= (T_LAB);
	return (1);
}

