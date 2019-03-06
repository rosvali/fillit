/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:33:15 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/03 18:30:09 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char	*)s;
	i = ft_strlen(str);
	while (i + 1 != 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	return (0);
}
