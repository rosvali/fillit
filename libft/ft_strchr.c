/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:31:13 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/04 16:48:46 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if ((char)c == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (str + i);
	}
	while (s[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}
