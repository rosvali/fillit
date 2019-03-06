/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:22:40 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/05 17:33:35 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_slen(char const *s)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
	{
		i++;
		if (s[i] == '\0')
			return (len);
	}
	while (s[i])
	{
		len++;
		i++;
	}
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i--;
		len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	if (ft_slen(s) > 0)
	{
		if (!(str = malloc(sizeof(char) * ft_slen(s) + 1)))
			return (NULL);
	}
	while (j < ft_slen(s))
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
