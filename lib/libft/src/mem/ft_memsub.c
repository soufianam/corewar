/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaxime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:06:38 by cmaxime           #+#    #+#             */
/*   Updated: 2018/03/23 17:06:57 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memsub(char *src, size_t start, size_t size)
{
	char	*new;
	size_t	i;

	new = ft_memalloc(size);
	i = start;
	while (i < start + size)
	{
		new[i - start] = src[i];
		i++;
	}
	return (new);
}

