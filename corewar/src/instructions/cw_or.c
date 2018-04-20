/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:08:22 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/20 15:01:02 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		cw_ocp(int ocp)
{
	if (ocp != 0x54 && ocp != 0xd4 && ocp != 0x74 &&\
			ocp != 0xf4 && ocp != 0x94 && ocp != 0x64 &&\
			ocp != 0xb4 && ocp != 0xe4 && ocp != 0xa4)
	{
		if (DEBUG)
			ft_printf("or: bad ocp %02x\n", ocp);
		return (0);
	}
	return (ocp);
}

int		cw_or_param(t_vm *vm, t_process *process, int param[3], int ret[3])
{
	int				i;
	int				check;
	int				offset;
	unsigned char	ocp;

	i = -1;
	check = 1;
	offset = 1;
	if (!(ocp = cw_ocp(vm->vm[(process->pc + process->entrypoint) % MEM_SIZE])))
		return (0);
	while (++i < 3)
	{
		if (!(ret[i] = cw_read_ocp(vm, process, &param[i], ocp)))
		{
			ret[i] += 1;
			check = 0;
		}
		offset += ret[i];
		if (ret[i] == 1 && i < 2)
			param[i] = cw_get_4(process->registries[param[i] - 1]);
		else if (ret[i] == 2)
			param[i] = cw_get_4(&(vm->vm[(process->pc + process->entrypoint
				- offset + ((short)param[i] % IDX_MOD)) % MEM_SIZE]));
		ocp = ocp << 2;
	}
	return (check);
}

int			cw_or(t_vm *vm, t_process *process)
{
	int				param[3];
	int				ret[3];

	process->pc = (process->pc + 1) % MEM_SIZE;
	if ((cw_or_param(vm, process, param, ret)))
	{
		cw_rev_get(process->registries[param[2] - 1], (param[0] | param[1]));
		process->carry = !(param[0] | param[1]) ? 1 : 0;
	}
	process->pc = (process->pc + 1) % MEM_SIZE;
	cw_wait_process(vm, process);
	if (DEBUG)
	{
		ft_printf("--cycle %d--\nor: %d | %d (%d) -> r%d\n", vm->cycle, param[0], param[1], param[0] | param[1], param[2]);
	}
	return (1);
}
