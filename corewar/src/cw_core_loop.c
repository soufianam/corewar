/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_core_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 09:11:00 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/23 10:55:58 by cmaxime          ###   ########.fr       */
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
		cw_process_process(vm.process, &vm, cycle);
		if (cycle == vm.setting.nbr_cycle)
			cw_dump_and_quit(&vm);
		cycle++;
		vm.cycle = cycle;
	}
}
