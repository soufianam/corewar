/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_visu_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:14:54 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/22 15:25:03 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	b;

	b = 'a';
	len = 0;
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		b = str[len - 1];
		str[len - 1] = str[i];
		str[i] = b;
		len--;
		i++;
	}
	return (str);
}

static int	nlen(uintmax_t n, int lbase)
{
	int len;

	len = 1;
	while (n / lbase != 0)
	{
		n /= lbase;
		len++;
	}
	return (len);
}

char		*cw_itoa_base(char n, char *base)
{
	int				i;
	char			*dst;
	int				lbase;

	lbase = ft_strlen(base);
	if (!(dst = (char*)malloc(nlen(n, lbase) + 1)))
		return (NULL);
	i = 0;
	dst[0] = '0';
	dst[1] = '0';
	while (n)
	{
		dst[i++] = base[n % lbase];
		n /= lbase;
	}
	dst[2] = '\0';
	dst = ft_strrev(dst);
	return (dst);
}
