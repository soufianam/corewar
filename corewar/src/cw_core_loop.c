/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 09:11:00 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/21 11:15:22 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_core_loop(t_vm vm)
{
	int	cycle;

	cycle = 0;
	while (1)
	{
		if (cycle == vm.loop.next_cycle_to_die)
		{
			cw_check_process(&vm, &cycle);
			vm.loop.next_cycle_to_die += vm.loop.cycle_to_die;
		}
		if (cycle == vm.loop.next_max_check)
		{
			vm.loop.cycle_to_die -= CYCLE_DELTA;
			vm.loop.next_cycle_to_die = cycle + vm.loop.cycle_to_die;
			vm.loop.next_max_check += vm.loop.cycle_to_die * MAX_CHECK;
		}
		if (cycle == vm.setting.nbr_cycle)
			; //cw_game_over();
		//cw_exec_process();
		cycle++;
	}
}
