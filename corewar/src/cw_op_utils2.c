/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_op_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 20:11:08 by tdeborde          #+#    #+#             */
/*   Updated: 2018/03/26 17:23:25 by tdeborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	*ft_memcpy_circle(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i = (i + 1) % MEM_SIZE;
	}
	return (dst);
}

void	cw_rev_get(char *registries, int nb)
{
	int		i;

	i = 4;
	while (--i)
	{
		registries[i] = (char)nb;
		nb = nb >> 8;
	}
}
