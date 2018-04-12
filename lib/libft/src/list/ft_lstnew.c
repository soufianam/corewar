/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:32:43 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/04/12 11:09:07 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t size)
{
	t_list	*lst;

	if ((lst = (t_list *)ft_memalloc(sizeof(t_list))) == 0)
		return (0);
	if (content)
	{
		lst->content = ft_memalloc(sizeof(unsigned char) * (size));
		if (lst->content)
		{
			ft_memcpy(lst->content, content, size);
			lst->content_size = size;
		}
	}
	else
	{
		lst->content = 0;
		lst->content_size = 0;
	}
	lst->next = 0;
	return (lst);
}
