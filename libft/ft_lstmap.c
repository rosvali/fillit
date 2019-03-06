/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:41:57 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/04 18:22:17 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*save;
	t_list	*tmp;

	save = (f)(lst);
	newlist = ft_lstnew(save->content, save->content_size);
	tmp = newlist;
	lst = lst->next;
	while (lst)
	{
		save = (f)(lst);
		newlist->next = ft_lstnew(save->content, save->content_size);
		newlist = newlist->next;
		lst = lst->next;
	}
	return (tmp);
}
