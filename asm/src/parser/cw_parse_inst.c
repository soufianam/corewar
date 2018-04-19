/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:12:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/19 17:33:51 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.h"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

/*
** return first occurences, in str match with one of the
** occurence of car. It's a case by case search.
** NON UTILISÉ.
*/

extern char		*ft_strostr(const char *str, const char *car)
{
	int			i;
	int			y;

	i = 0;
	while (str[i] != '\0')
	{
		y = 0;
		while (car[y] != '\0')
		{
			if (str[i] == car[y])
				return ((char *)(&str[i]));
			y++;
		}
		i++;
	}
	return (0);
}

static int8_t	cw_isset_instruct(char *instruct)
{
	int		i;

	i = 0;
	while (i < OP_TAB_SIZE - 1)
	{
		if (!ft_strcmp(instruct, optab[i].ins))
			return (optab[i].opcode - 1);
		i++;
	}
	return (-1);
}

static void		cw_clear_first_param(char *fparam)
{
	int 	i;
	int		y;

	i = 0;
	y = 0;
	while (!ft_strchr(" ", fparam[y]))
		y++;
	while (fparam[y] != '\0')
	{
		fparam[i] = fparam[y];
		i++;
		y++;
	}
	fparam[i] = '\0';
}

extern int		cw_parse_instruct(char *instruct, t_instruct **inst, char ***param)
{
	int8_t	id;
	char 	**ins;

	ft_strsanitalize(instruct, "\t ");
	ins = ft_strsplit(instruct, ' ');
	if (ins == 0)
		return (-1); //Pas d'instruction
	if ((id = cw_isset_instruct(ins[0])) == -1)
		return (-1); //L'instruction n'existe pas
	(*inst)->id = id;
	(*param) = ft_strsplit(instruct, SEPARATOR_CHAR);
	cw_clear_first_param(**param);
	return (1);
}
