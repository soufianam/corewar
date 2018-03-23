/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:48:28 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/23 12:58:14 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_vm_init(t_vm *vm, int ac, char **av)
{

	vm->cycle = 0;
	if (!(vm->vm = ft_memalloc(MEM_SIZE)))
		cw_error(ERR_MALLOC);
	vm->loop.next_cycle_to_die = CYCLE_TO_DIE;
	vm->loop.next_max_check = MAX_CHECKS * CYCLE_TO_DIE;
	vm->loop.cycle_to_die = CYCLE_TO_DIE;
	vm->loop.last_live.index = -1;
	vm->loop.last_live.cycle = -1;
	if (cw_load_settings(&(vm->setting), ac, av) <= 1)
		cw_error(ERR_USAGE);
	cw_create_process(vm);
}
