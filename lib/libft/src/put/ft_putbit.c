/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:41:13 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/16 18:42:13 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_base2(unsigned char val, char *str)
{
	int	i;
	int	bits;

	i = 7;
	bits = 8;
	str[8] = '\0';
	while (bits > 0)
	{
		str[i] = (val % 2) + 48;
		val /= 2;
		i--;
		bits--;
	}
	return (str);
}

extern void		ft_putbit(void *data, size_t n)
{
	char		*tmp;
	char		str[sizeof(unsigned char) * 8 + 1];
	char		*bits;

	tmp = data;
	if ((bits = ft_strnew(sizeof(unsigned char) * 8 * n + 1)))
	{
		while (n--)
			ft_strcat(bits, ft_base2(*(tmp + n), str));
		ft_putstr(bits);
		ft_strdel((char **)&bits);
	}
}
