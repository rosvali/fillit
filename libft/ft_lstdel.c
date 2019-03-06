/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:25:58 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/05 17:39:42 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (*alst)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = (*alst)->next;
	}
	*alst = NULL;
}
