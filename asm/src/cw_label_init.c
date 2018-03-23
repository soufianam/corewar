/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_label_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:58:08 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/23 16:58:18 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** fct
*/
int		cw_get_addr_from_label(char *label, t_list *list)
{
	t_instruct *inst;

	while (list)
	{
		inst = list->content;
		if (ft_strcmp(inst, label) == 0)
			return (inst->pc);
		list = list->next;
	}
	return (-1);
}

