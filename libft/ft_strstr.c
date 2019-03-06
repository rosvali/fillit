/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:29:49 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/03 17:19:21 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 1;
	if (s2[j] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			while (s1[i] && s2[j] && s1[i] == s2[j])
			{
				j++;
				i++;
			}
			if (s2[j] == '\0')
				return ((char *)s1 + k - 1);
		}
		j = 0;
		i = k++;
	}
	return (NULL);
}
