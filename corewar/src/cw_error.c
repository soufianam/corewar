/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:12:56 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/22 15:30:52 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cw_error(int err)
{
	static const char *error[3] = {
		"unknown error",
		"usage: ./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...",
		"malloc error"
	};

	ft_putendl(error[err]);
	exit(1);
}
