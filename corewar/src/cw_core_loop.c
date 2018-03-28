/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 09:11:00 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/28 17:44:55 by tdeborde         ###   ########.fr       */
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
			cw_check_process(&vm);
			vm.loop.next_cycle_to_die += vm.loop.cycle_to_die;
		}
		if (cycle == vm.loop.next_max_check)
		{
			vm.loop.cycle_to_die -= CYCLE_DELTA;
			vm.loop.next_cycle_to_die = cycle + vm.loop.cycle_to_die;
			vm.loop.next_max_check += vm.loop.cycle_to_die * MAX_CHECKS;
		}
		if (cycle == vm.setting.nbr_cycle)
			cw_dump_and_quit(&vm);
		cw_process_process(vm.process, &vm, cycle);
		cycle++;
	}
}
