/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:36:34 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/01 20:36:37 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_place(char *map, char *tab, int i)
{
	int		len;
	int		diff;
	int		count;
	int		j;
	int		k;

	len = (int)tab_len(tab);
	count = 0;
	j = 0;
	k = 0;
	diff = 4 - len;
	while (i < (int)ft_strlen(tab) && k < (int)tab_len(tab) && len <= 16)
	{
		while (i < (int)ft_strlen(tab) && tab[i] && map[j] && j < len)
		{
			if (tab[i] == '.' && map[j] == '#')
			{
				if ((i + 1) % (int)tab_len(tab) == 0 && map[j + 1] == '#')
					return (0);
				count++;
				if (count == 4)
					return (1);
			}
			i++;
			j++;
		}
		j += diff;
		len += diff + len;
		k++;
	}
	return (0);
}

int		can_place_sup(char *map, char *tab, int i)
{
	int		len;
	int		diff;
	int		count;
	int		lim;
	int		j;
	int		k;

	len = 4;
	count = 0;
	j = 0;
	k = 0;
	lim = 0;
	diff = (int)tab_len(tab) - 4;
	while (i < (int)ft_strlen(tab) && k < 4 && len <= (int)ft_strlen(tab))
	{
		while (i < (int)ft_strlen(tab) && lim < 4)
		{
			if (tab[i] == '.' && map[j] == '#')
			{
				if ((i + 1) % (int)tab_len(tab) == 0 && map[j + 1] == '#')
					return (0);
				count++;
				if (count == 4)
					return (1);
			}
			i++;
			j++;
			lim++;
		}
		i += diff;
		len += diff + 4;
		k++;
		lim = 0;
	}
	return (0);
}
