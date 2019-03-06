/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:18:14 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/14 14:21:08 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
