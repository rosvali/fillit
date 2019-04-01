/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:48:21 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/01 19:20:45 by kwatanab         ###   ########.fr       */
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

void	place(char *map, char *tab, char c, int i)
{
	int		len;
	int		count;
	int		diff;
	int		j;
	int		k;

	len = (int)tab_len(tab);
	j = 0;
	k = 0;
	count = 0;
	diff = 4 - len;
	while (i < (int)ft_strlen(tab) && k < (int)tab_len(tab) && len <= 16 && count != 4)
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

void	place_sup(char *map, char *tab, char c, int i)
{
	int		len;
	int		diff;
	int		lim;
	int		j;
	int		k;
	int		count;

	len = 4;
	j = 0;
	k = 0;
	lim = 0;
	count = 0;
	diff = (int)tab_len(tab) - 4;
	while (i < (int)ft_strlen(tab) && k < 4 && len <= (int)ft_strlen(tab))
	{
		while (i < (int)ft_strlen(tab) && lim < 4)
		{
			if (tab[i] == '.' && map[j] == '#')
			{
				tab[i] = c;
				count++;
			}
			if (count == 4)
				break ;
			i++;
			j++;
			lim++;
		}
		if (count == 4)
			break ;
		i += diff;
		len += diff + 4;
		k++;
		lim = 0;
	}
}
