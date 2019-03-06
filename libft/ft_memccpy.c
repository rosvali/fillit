/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:56:02 by raguillo          #+#    #+#             */
/*   Updated: 2018/11/28 14:16:32 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*desti;
	unsigned char	*srci;

	i = 0;
	desti = (unsigned char *)dest;
	srci = (unsigned char *)src;
	while (i < n)
	{
		if (srci[i] == (unsigned char)c)
		{
			desti[i] = srci[i];
			return (desti + i + 1);
		}
		desti[i] = srci[i];
		i++;
	}
	return (NULL);
}
