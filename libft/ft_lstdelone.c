/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:16:50 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/05 17:35:51 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		if (del && (*alst)->content)
			(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
