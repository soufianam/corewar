/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:41:19 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/23 10:36:59 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			cw_aff(t_vm *vm, t_process *process)
{
	unsigned int	param;
	char			aff;

	param = cw_get_1(&(vm->vm[(process->pc + process->entrypoint + 2) % MEM_SIZE]));
	aff = cw_get_4(process->registries[param - 1]) % 256;
	process->pc = (process->pc + 3) % MEM_SIZE;
	ft_printf("%C\n", (unsigned char)aff);
	cw_wait_process(vm, process);
	if (DEBUG)
	{
		ft_printf("--cycle %d--\naff: r%d (%d)\n", vm->cycle, param, aff);
	}
	return (1);
}
