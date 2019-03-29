/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:49:01 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/29 17:57:10 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	tetro_shift(char *piece, size_t n)
{
	size_t i;

	i = 0;
	while (i < 16)
	{
		piece[i] = (i + n >= 16 ? '.' : piece[i + n]);
		++i;
	}
}

void	tetro_shift_left(char *piece)
{
	while (piece[0] == '.' && piece[4] == '.'
		&& piece[8] == '.' && piece[12] == '.')
		tetro_shift(piece, 1);
}

void	tetro_shift_top(char *piece)
{
	while (piece[0] == '.' && piece[1] == '.'
		&& piece[2] == '.' && piece[3] == '.')
		tetro_shift(piece, 4);
}

char	*grow_and_solve(t_tetro *t)
{
	char	*tab;
	char	c;
	int		count;

	c = 'A';
	count = 4;
	if (!(tab = create_final_tab(&count)))
		return (NULL);
	while (backtracking(t, c, tab) == 0)
	{
		count++;
		free(tab);
		if (!(tab = create_final_tab(&count)))
			return (NULL);
	}
	return (tab);
}

int		can_place(char *map, char *tab, int i)
{
	int		len;
	int		def_len;
	int		diff;
	int		count;
	int		j;
	int		k;

	len = (int)tab_len(tab);
	def_len = len;
	count = 0;
	j = 0;
	k = 0;
	diff = 4 - len;
	while (k < def_len && len <= 16)
	{
		while (j < len)
		{
			if (tab[i] == '.' && map[j] == '#')
			{
				if ((i + 1) % def_len == 0 && map[j + 1] == '#')
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
	int		def_len;
	int		diff;
	int		j;
	int		k;

	len = (int)tab_len(tab);
	def_len = len;
	j = 0;
	k = 0;
	diff = 4 - len;
	while (k < def_len && len <= 16)
	{
		while (j < len)
		{
			if (tab[i] == '.' && map[j] == '#')
				tab[i] = c;
			i++;
			j++;
		}
		j += diff;
		len += diff + len;
		k++;
	}
}

void	place_del(char *map, char *tab, char c, int i)
{
	int		len;
	int		def_len;
	int		diff;
	int		j;
	int		k;

	len = (int)tab_len(tab);
	def_len = len;
	j = 0;
	k = 0;
	diff = 4 - len;
	while (k < def_len && len <= 16)
	{
		while (j < len)
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

int		can_place_sup(char *map, char *tab, int i)
{
	int		len;
	int		def_len;
	int		diff;
	int		count;
	int		lim;
	int		j;
	int		k;

	len = 4;
	def_len = (int)tab_len(tab);
	count = 0;
	j = 0;
	k = 0;
	lim = 0;
	diff = def_len - 4;
	while (k < 4 && len <= (int)ft_strlen(tab))
	{
		while (lim < 4)
		{
			if (tab[i] == '.' && map[j] == '#')
			{
				if ((i + 1) % def_len == 0 && map[j + 1] == '#')
					return (0);
				count++;
			}
			i++;
			j++;
			lim++;
		}
		i += diff;
		len += diff + len;
		k++;
		lim = 0;
	}
	if (count == 4)
		return (1);
	return (0);
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
	lim = 0;
	diff = (int)tab_len(tab) - 4;
	while (k < 4 && len <= (int)ft_strlen(tab))
	{
		while (lim < 4)
		{
			if (tab[i] == '.' && map[j] == '#')
				tab[i] = c;
			i++;
			j++;
			lim++;
		}
		i += diff;
		len += diff + len;
		k++;
		lim = 0;
	}
}

void	place_sup_del(char *map, char *tab, char c, int i)
{
	int		len;
	int		diff;
	int		lim;
	int		j;
	int		k;

	len = 4;
	j = 0;
	k = 0;
	lim = 0;
	diff = (int)tab_len(tab) - 4;
	while (k < 4 && len <= (int)ft_strlen(tab))
	{
		while (lim < 4)
		{
			if (tab[i] != '.' && map[j] == '#')
				tab[i] = c;
			i++;
			j++;
			lim++;
		}
		i += diff;
		len += diff + len;
		k++;
		lim = 0;
	}
}

int		backtracking(t_tetro *t, char c, char *tab)
{
	int		i;

	i = 0;
	if (t == NULL)
		return (1);
	while (tab[i])
	{
		if (tab[i] == '.')
		{
			if (ft_strlen(tab) <= 16)
			{
				if (can_place(t->map, tab, i) == 1)
				{
					place(t->map, tab, c, i);
					if (backtracking(t->next, (c + 1), tab))
						return (1);
					else
						place_del(t->map, tab, '.', i);
				}
			}
			else
			{
				if (can_place_sup(t->map, tab, i) == 1)
				{
					place_sup(t->map, tab, c, i);
					if (backtracking(t->next, (c + 1), tab))
						return (1);
					else
						place_sup_del(t->map, tab, '.', i);
				}
			}
		}
		i++;
	}
	return (0);
}
