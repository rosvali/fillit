/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:34:05 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/03 17:46:33 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		n--;
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return ((unsigned char *)dest);
}
