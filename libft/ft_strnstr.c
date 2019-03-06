/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:29:23 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/03 19:30:57 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 1;
	if (s2[j] == '\0' || s1 == s2)
		return ((char *)s1);
	while (i < n && s1[i])
	{
		if (s1[i] == s2[j])
		{
			while (i < n && s1[i] && s2[j] && s1[i] == s2[j])
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
