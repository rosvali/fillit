/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:48:21 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/03 19:29:36 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_initializer(int *count, int *k, int *j, char *tab)
{
	int	diff;

	*j = 0;
	*k = 0;
	*count = 0;
	diff = 4 - (int)tab_len(tab);
	return (diff);
}

void	place(char *map, char *tab, char c, int i)
{
	int		len;
	int		count;
	int		j;
	int		k;
	int		diff;

	len = (int)tab_len(tab);
	diff = place_initializer(&count, &k, &j, tab);
	while (i < (int)ft_strlen(tab) && k < (int)tab_len(tab)
	&& len <= 16 && count != 4)
	{
		while (i < (int)ft_strlen(tab) && j < len && count != 4)
		{
			if (tab[i] == '.' && map[j] == '#')
			{
				tab[i] = c;
				count++;
			}
			i++;
			j++;
		}
		j += diff;
		len += diff + len;
		k++;
	}
}

void	place_sup(char *map, char *tab, char c, int i)
{
	int		len;
	int		diff;
	int		lim;
	int		j;
	int		k;

	len = 4;
	j = 0;
	k = 0;
	diff = (int)tab_len(tab) - 4;
	while (i < (int)ft_strlen(tab) && k < 4 && len <= (int)ft_strlen(tab))
	{
		lim = 0;
		while (i < (int)ft_strlen(tab) && lim < 4)
		{
			if (tab[i] == '.' && map[j] == '#')
				tab[i] = c;
			i++;
			j++;
			lim++;
		}
		i += diff;
		len += diff + 4;
		k++;
	}
}
