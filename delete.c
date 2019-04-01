/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:57:46 by raguillo          #+#    #+#             */
/*   Updated: 2019/04/01 19:17:28 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_block(char *map, char *tab, char c, int i)
{
	int		len;
	int		diff;
	int		j;
	int		k;

	len = (int)tab_len(tab);
	j = 0;
	k = 0;
	diff = 4 - len;
	while (i < (int)ft_strlen(tab) && k < (int)tab_len(tab) && len <= 16)
	{
		while (i < (int)ft_strlen(tab) && tab[i] && map[j] && j < len)
		{
			if (tab[i] != '.' && map[j] == '#')
				tab[i] = c;
			i++;
			j++;
		}
		j += diff;
		len += diff + len;
		k++;
	}
}

void	delete_block_sup(char *map, char *tab, char c, int i)
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
			if (tab[i] != '.' && map[j] == '#')
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
