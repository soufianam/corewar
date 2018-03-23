/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:13:05 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/23 19:55:37 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.c"
#include "libft.h"
#include "asm.h"

int			ft_count_param(char **param)
{
	int		i;

	i = 0;
	while (param[i] != '\0')
		i++;
	return (++i);
}

int			ft_parse_param(char *param_line, t_instruct *inst, char **param)
{
	char	**param_list;
	int		nb_param;
	int 	ret;
	int		i;

	if (!(param_list = ft_strsplit(param_line, SEPARATOR_CHAR)))
		return (0);
	if ((nb_param = ft_count_param(param)) > ft_count_op_param(optab[ins->id]))
		return (0);
	i = 0;
	ret = 1;
	while (i < MAX_ARG_NUMBER)
	{
		if (i < nb_param)
		{
			if (!(ret = t_insert_param(param_list[i], ins, i)))
				break ;
		}
		else
			ret = ft_insert_param(0, ins, i);
	}
	ft_strdel_splittab(param);
	return (ret;)
}
