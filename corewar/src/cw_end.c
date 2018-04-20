/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:11:23 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/20 14:39:13 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/**/
/*debug*/
void	cw_dump_all(t_vm *vm)
{
	int i;
	/*cycle*/
	ft_printf("Cycle: %d\n", vm->cycle);
	/*players*/
	i = 0;
	while (i < vm->setting.nbr_champion)
	{
		ft_printf("Player %d: %s\n", vm->setting.champion_tab[i].id, vm->setting.champion_tab[i].name);
		i++;
	}
	/*process*/
	t_list *lst;
	t_process *process;
	lst = vm->process;
	while (lst)
	{
		L("");
		process = lst->content;
		i = 0;
		while (i < REG_NUMBER - 1)
		{
			printf("%d|", cw_get_4(process->registries[i]));
			i++;
		}
		printf("%d\t(registres)\n", cw_get_4(process->registries[i]));
		printf("%-*d(entrypoint)\n", REG_NUMBER*2, process->entrypoint);
		printf("%-*d(pc)\n", REG_NUMBER*2, process->pc);
		printf("%-*d(carry)\n", REG_NUMBER*2, process->carry);
		printf("%-*d(next_cycle)\n", REG_NUMBER*2, process->next_cycle);
		printf("%-*d(live)\n", REG_NUMBER*2, process->live);
		lst = lst->next;
	}
}
/**/

void	cw_dump_and_quit(t_vm *vm)
{
	int		i;
	char	*res;

	res = 0;
	i = 0;
	ft_printf("%#06x : ", 0);
	while (i < MEM_SIZE)
	{
		ft_printf("%02x", vm->vm[i]);
		if ((i + 1) % 64 != 0)
			ft_putchar(' ');
		else
		{
			ft_putchar('\n');
			if (i != MEM_SIZE - 1)
				ft_printf("%#06x : ", i +1);
		}
		i++;
	}
	if (DEBUG)
		cw_dump_all(vm);
	exit(0);
}

void	cw_game_over(t_vm *vm)
{
	t_champion	*champ;
	int		index;

	index = vm->loop.last_live.index;
	champ = cw_find_player(&(vm->setting), index);
	if (DEBUG)
		ft_printf("--cycle %d--\n", vm->cycle);
	if (index == -1 || !champ)
		ft_printf("No process found living for a champion\n");
	else
		ft_printf("Player %d %s won\n", index, champ->name);
	exit(0);
}
