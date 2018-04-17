/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_prog_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:13:09 by cmaxime           #+#    #+#             */
/*   Updated: 2018/04/17 19:06:21 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_putbin(char *bin, int size)
{
	int 	i;

	i = -1;
	while (++i < size)
		ft_printf("%0.2hhx ", bin[i]);
	ft_putchar('\n');
}

/*
** fct to add a param to the program
*/
int		cw_add_param(t_param param, char **bin, int add, int size)
{
	char	*p;
	int		i;

	p = ft_memalloc(add);
	i = -1;
	while (++i < add)
		p[i] = (char)((param.val << (i * 8)) >> (8 * (add - 1)));
	ft_putbin(p, add); ft_putnbr(param.val); ft_putstr("\n");
	*bin = ft_memextend(*bin, p, size, add);
	free(p);
	return (add);
}

/*
** fct to get the size of a param
*/
int		cw_size_param(t_param param, int8_t id)
{
	int		dir;
	int		size;

	dir = optab[id - 1].codage;
	size = 0;
	if ((param.pid & 0b00000100) != 0)
		size = 2;
	else if ((param.pid & 0b00000010) != 0)
		size = (dir == 1 && (id < 3 || id > 5) && id != 16) ? 2 : 4;
	else if ((param.pid & 0b00000001) != 0)
		size = 1;
	return (size);
}

/*
** fct to add an instruction to the prog
*/
int		cw_compile_instruct(t_instruct *inst, char **bin, int size)
{
	int		i;
	int		add;
	char	*p;
	int		s_p;

	s_p = 1;
	if ((inst->ocp & 0b01111100) != 0)
		s_p = 2;
	p = ft_memalloc(s_p);
	p[0] = inst->id + 1;
	if (s_p == 2)
		p[1] = inst->ocp;
	*bin = ft_memextend(*bin, p, size, s_p);
	size += s_p;
	free(p);
	i = -1;
	while (++i < 3)
	{
		add = cw_size_param(inst->param[i], inst->id);
		if (add != 0)
			size += cw_add_param(inst->param[i], bin, add, size);
	}
	return (size);
}

/*
** fcts to init in and get the size of bin and allocate the bin
*/
int		cw_prog_init(t_list *list, char **bin)
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
		ft_putbin(*bin, size);
		cmd = cmd->next;
	}
	return (size);
}
