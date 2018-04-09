/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:06:01 by cmaxime           #+#    #+#             */
/*   Updated: 2018/04/09 15:41:02 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memextend(char *dst, char *src, size_t sz_d, size_t sz_s)
{
	char	*tmp;

	dst = ft_memrealloc(dst, sz_d + sz_s);
	tmp = dst + sz_d;
	tmp = ft_memcpy(tmp, src, sz_s);
	return (dst);
}

