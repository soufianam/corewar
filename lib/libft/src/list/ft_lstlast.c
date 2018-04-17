/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:41:22 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/17 16:41:23 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list **elem)
{
	t_list		*last;

	if (*elem)
	{
		last = *elem;
		while (last->next != 0)
			last = last->next;
		return (last);
	}
	return (0);
}
