/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_inst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:12:37 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/23 18:15:50 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs>
#include "op.c"
#include "asm.h"

extern t_op		optab[OP_TAB_SIZE];

int8_t			ft_isset_instruct(char *instruct)
{
	int		i;

	i = 0;
	while (i < OP_TAB_SIZE)
	{
		if (!ft_strcmp(instruct, optab[i].ins)
			return (optab[i].opcode);
	}
	return (-1);
}

int			ft_parse_instruction(char *instruct, t_instruct *inst, char **param)
{
	char	**ins;
	int8_t	id;

	param = ft_strsplit(instruct, '\t');
	if ((id = ft_isset_instruct(param[0])) == -1)
		return (0);
	ins->id = id;
	return (1);
}
