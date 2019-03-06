/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:28:30 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/03 16:46:25 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countnb(int n)
{
	size_t		len;
	long		nb;

	len = 1;
	nb = n;
	if (nb == -2147483648)
		ft_countnb(-0);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*str;
	size_t		res;

	i = 0;
	res = n;
	if (!(str = ft_strnew(ft_countnb(n))))
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		res = res * -1;
	}
	i = ft_countnb(n) - 1;
	while (res > 9)
	{
		str[i] = res % 10 + '0';
		res = res / 10;
		i--;
	}
	str[i] = res + '0';
	return (str);
}
