/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:32:07 by tdeborde          #+#    #+#             */
/*   Updated: 2018/04/23 11:58:25 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		cw_ocp(int ocp)
{
	if (ocp != 0x50 && ocp != 0x70)
	{
		if (DEBUG)
			ft_printf("st: bad ocp %02x\n", ocp);
		return (0);
	}
	return (ocp);
}

int		cw_st_param(t_vm *vm, t_process *process, int param[2], int ret[2])
{
	int				i;
	int				check;
	unsigned char	ocp;

	i = -1;
	check = 1;
	if (!(ocp = cw_ocp(vm->vm[(process->pc + process->entrypoint) % MEM_SIZE])))
		return (0);
	while (++i < 2)
	{
		if (!(ret[i] = cw_read_ocp(vm, process, &param[i], ocp)))
		{
			ret[i] += 1;
			check = 0;
		}
		ocp = ocp << 2;
	}
	return (check);
}

int		cw_st(t_vm *vm, t_process *process)
{
	int				param[2];
	int				ret[2];

	process->pc = (process->pc + 1) % MEM_SIZE;
	if ((cw_st_param(vm, process, param, ret)))
	{
		if (ret[1] == 1)
			ft_memcpy(process->registries[param[1] - 1],
					process->registries[param[0] - 1], REG_SIZE);
		else
			ft_memcpy(&(vm->vm[(unsigned int)(process->pc + process->entrypoint + 
				((short)param[1] % IDX_MOD) - ret[1] - 2) % MEM_SIZE]),
					process->registries[param[0] - 1], REG_SIZE);
	}
	process->pc = (process->pc + 1) % MEM_SIZE;
	cw_wait_process(vm, process);
	if (DEBUG)
	{
		ft_printf("--cycle %d--\nst: r%d (%d) -> %.1s%d\n", vm->cycle, param[0], cw_get_4(process->registries[param[0] - 1]), ret[1] == 1 ? "r" : "", param[1]);
	}
	return (1);
}
