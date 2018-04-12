/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:46:39 by pprikazs          #+#    #+#             */
/*   Updated: 2018/04/12 10:46:44 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstpushb(t_list **alst, t_list *new_one)
{
	t_list		*last;

	if (*alst)
	{
		last = *alst;
		while (last->next != 0)
			last = last->next;
		last->next = new_one;
	}
	else
		*alst = new_one;
}
