/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:45:33 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/21 18:59:26 by blefeuvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelif(t_list **begin_list, void *content_ref, int (*cmp)())
{
	t_list	*head;
	t_list	*prev;

	prev = 0;
	if (!begin_list)
		return ;
	head = *begin_list;
	while (head != 0)
	{
		if (cmp(head->content, content_ref) == 0)
		{
			if (prev == 0)
				*begin_list = head->next;
			else
				prev->next = head->next;
			ft_memdel((void**)&head);
		}
		prev = head;
		if (head)
			head = head->next;
	}
}
