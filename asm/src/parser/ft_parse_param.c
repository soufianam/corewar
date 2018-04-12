/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:13:05 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/12 16:55:24 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/cdefs.h>
#include "op.h"
#include "libft.h"
#include "asm.h"

int			ft_count_param(char **param)
{
	int		i;

	i = 0;
	while (param[i] != '\0')
		i++;
	return (i);
}

int			ft_parse_param(t_instruct **inst, char **param)
{
	int		nb_param;
	int 	ret;
	int		i;

	if (param == 0)
		return (1);
	if ((nb_param = ft_count_param(param)) > optab[(*inst)->id].nb_param)
		return (0);
	i = 0;
	ret = 1;
	while (i < MAX_ARGS_NUMBER)
	{
		if (i < nb_param)
		{
			if (!(ret = ft_insert_param(param[i], inst, i)))
				break ;
		}
		else
			ret = ft_insert_param(0, inst, i);
		i++;
	}
	return (ret);
}
