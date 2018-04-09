/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:56:30 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/09 12:37:38 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_champions_data(t_setting *setting)
{
	int			i;
	t_champion	*c;
	int			j;

	c = setting->champion_tab;
	L("Champion data");
	i = -1;
	while (++i < setting->nbr_champion)
	{
		L(c[i].name);
		N(c[i].id);
		L("");
		NL(c[i].size_prog);
		j = -1;
		while (++j < c[i].size_prog)
			ft_printf("%02hhx ", c[i].bin[j]);
		L("\n");
	}
}

int		main(int ac, char **av)
{
	t_vm		vm;

	cw_vm_init(&vm, ac, av);
//	print_champions_data(&(vm.setting));
	vm.setting.champion_tab[0].bin[6] = 0x01;
	cw_core_loop(vm);
	return (0);
}
