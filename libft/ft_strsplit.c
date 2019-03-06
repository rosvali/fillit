/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:42:40 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/05 17:38:02 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

static int	ft_countletter(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		y;
	char	**tab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = malloc(sizeof(char *) * (ft_countword(s, c) + 1))))
		return (NULL);
	while (j < ft_countword(s, c))
	{
		y = 0;
		while (s[i] == c)
			i++;
		if (!(tab[j] = malloc(sizeof(char) * (ft_countletter(s, c, i) + 1))))
			return (NULL);
		while (s[i] != c && s[i])
			tab[j][y++] = s[i++];
		tab[j][y] = '\0';
		j++;
	}
	tab[j] = 0;
	return (tab);
}
