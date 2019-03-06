/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:44:56 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/04 18:26:39 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		*str;
	int		i;

	if (min >= max)
		return (NULL);
	if (!(str = (int*)malloc(sizeof(*str) * (max - min))))
		return (NULL);
	i = 0;
	while (min < max)
	{
		str[i] = min;
		i++;
		min++;
	}
	return (str);
}
