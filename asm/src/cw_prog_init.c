/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_prog_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:13:09 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/23 17:08:40 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** fct
*/
int		cw_add_param(t_param param, char *bin, int add, int size)
{
	char	*p;
	int		i;

	p = memalloc(add);
	i = -1;
	while (++i < add)
		p[i] = (char)((param.val << (i * 8)) >> (8 * add));
	return (add);
}

/*
** fct
*/
int		cw_size_param(t_param param, int8_t id)
{
	int		dir;
	int		size;

	dir = optab[id - 1].codage;
	size = 0;
	if (param.pid / 4 == 1)
		size = 2;
	else if (param.pid / 2 == 1)
		size = dir == 1 ? 2 : 4;
	else if (param.pid == 1)
		size = 1;
	return (size);
}

/*
** fct to add an instruction to the prog
*/
int		cw_compile_instruct(t_instruct *inst, char *bin, int size)
{
	int		i;
	int		add;

	i = -1;
	while (++i < 3)
	{
		add = cw_size_param(inst->param[i], inst->id);
		size += cw_add_param(inst->param[i], bin, add, size);
	}
	return (size);
}

/*
** fcts to init in and get the size of bin and allocate the bin
*/
int		cw_prog_init(t_list *list, char *bin)
{
	int			size;
	t_instruct	*inst;
	t_list		*cmd;

	size = 0;
	cmd = list;
	while (cmd)
	{
		inst = cmd->content;
		size = cw_compile_instruct(inst, bin, size);
		cmd = cmd->next;
	}
	return (size);
}
