/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:45:01 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/01 17:33:57 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*desti;
	unsigned char	*srci;

	i = 0;
	desti = (unsigned char *)dest;
	srci = (unsigned char *)src;
	while (i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	return (dest);
}
