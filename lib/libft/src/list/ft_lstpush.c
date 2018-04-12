/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:45:47 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/12 12:39:28 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstpush(t_list **alst, void *data, size_t content_size, \
		void (*f)(t_list **list, t_list *elem))
{
	t_list		*elem;

	if (*alst == 0)
	{
		if (!(*alst = ft_lstnew(data, content_size)))
			return (0);
	}
	else
	{
		if (!(elem = ft_lstnew(data, content_size)))
			return (0);
		f(alst, elem);
	}
	return (1);
}
