/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_exec_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:26:12 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/21 11:53:34 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_process_process(t_process *process, int *vmi, int cycle)
{
	t_process *curr;

	curr = process;
	while (curr)
	{
		if (curr->cycle == cycle)
			; //cw_exec_process();
		curr = curr->next;
	}
}
