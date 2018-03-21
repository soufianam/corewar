/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vm_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 08:48:28 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/21 09:18:46 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_vm_init(t_vm *vm)
{

	vm->cycle = 0;
	if (!(vm->vm = ft_memalloc(MEM_SIZE)))
		cw_error(ERR_MALLOC);
	vm->loop.next_cycle_to_die = CYCLE_TO_DIE;
	vm->loop.next_mac_check = MAX_CHECK * CYCLE_TO_DIE;
	//cw_load_settings(&(vm->setting), ac, av);
	//create processes
}
