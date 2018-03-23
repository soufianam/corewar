/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:12:56 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/23 13:00:58 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_error(int err)
{
	static const char *error[] = {
		"Error: unknown",
		"usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...",
		"Error: malloc failed"
	};

	ft_putendl(error[err]);
	exit(1);
}

int		cw_error_custom(char *str)
{
	ft_putendl(str);
	exit(1);
}
