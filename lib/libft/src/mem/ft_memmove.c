/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:03:16 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/02/28 14:48:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		*ft_memmove(void *ptrd, const void *ptrs, size_t n)
{
	unsigned char	*tmp_ptrd;
	unsigned char	*tmp_ptrs;
	int				ope;
	int				end;

	tmp_ptrd = (unsigned char *)ptrd;
	tmp_ptrs = (unsigned char *)ptrs;
	ope = 1;
	end = n + 1;
	if (tmp_ptrd > tmp_ptrs)
	{
		tmp_ptrd--;
		tmp_ptrs--;
		tmp_ptrd += n;
		tmp_ptrs += n;
		ope = -ope;
		end = 0;
	}
	while (tmp_ptrs != (ptrs + end - 1) && tmp_ptrd != tmp_ptrs)
	{
		*tmp_ptrd = *tmp_ptrs;
		tmp_ptrd += ope;
		tmp_ptrs += ope;
	}
	return (ptrd);
}
