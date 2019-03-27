/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:49:01 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/27 19:36:14 by kwatanab         ###   ########.fr       */
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

// int	can_place(char *map, char *tab, int i)
// {
// 	int tab_size;
// 	int tab_len;
// 	int j;
// 	int k;

// 	tab_size = ft_strlen(tab);
// 	tab_len = ft_sqrt(tab_size);
// 	j = i;
// 	k = 0;
// 	while (k < 16)
// 	{
// 		if (map[k] == '#' && (((i % tab_len) + (k % 4) >= tab_len)
// 			|| (j >= tab_size) || (tab[j] != '.')))
// 			return (0);
// 		if (tab_len > 4 && j && j % tab_len == 0)
// 			j += tab_len - 4;
// 		else
// 			++j;
// 		++k;
// 	}
// 	return (1);
// }

// void	place(char *map, char *tab, char c, int i)
// {
// 	int tab_size;
// 	int tab_len;
// 	int j;
// 	int k;
// 	int	spc;

// 	tab_size = ft_strlen(tab);
// 	tab_len = ft_sqrt(tab_size);
// 	j = i;
// 	spc = tab_len - 5;
// 	k = 0;
// 	while (k < 16)
// 	{
// 		if (map[k] == '#')
// 			tab[j] = c;
// 		if (tab_len != 4 && j && j % tab_len == 0)
// 			j += tab_len - 4;
// 		else 
// 			++j;
// 		++k;
// 	}
// }

int		can_place(char *map, char *tab, int i)
{
	// int len;
	// int def_len;
	// int diff;
	// int count;
	// int j;
	// int k;
	
	// len = (int)ft_len(tab);
	// def_len = len;
	// count = 0;
	// j = 0;
	// k = 0;
	// if (len <= 4)
	// 	diff = 4 - len;
	// else
	// 	diff = len - 4;
	// while (k < def_len)
	// {
	// 	while (j < len)
	// 	{
	// 		if (tab[i] == '.' && map[j] == '#')
	// 			count++;
	// 		i++;
	// 		j++;
	// 	}
	// 	j += diff;
	// 	len += diff + len;
	// 	k++;
	// }
	// if (count == 4)
	// 	return (1);
	// return (0);

	int len;
	int def_len;
	int diff;
	int count;
	int j;
	int k;

	len = (int)ft_len(tab);
	def_len = len;
	count = 0;
	j = 0;
	k = 0;
	if (len <= 4)
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
			}
			i++;
			j++;
		}
		j+= diff;
		len += diff + len;
		k++;
	}
	if (count == 4)
		return (1);
	return (0);
}

void	place(char *map, char *tab, char c, int i)
{
	int len;
	int def_len;
	int diff;
	int j;
	int k;
	
	len = (int)ft_len(tab);
	def_len = len;
	j = 0;
	k = 0;
	if (len <= 4)
	{
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
}

// int		can_place(char *map, char *tab, int i)
// {
// 	int	count;
// 	int	spc;
// 	int j;
// 	int	len;

// 	len = ft_len(tab);
// 	spc = len - 5;
// 	count = 0;
// 	j = 0;
// 	while (count < 4)
// 	{
// 		if (tab[i] == '\0' || map[j] == '\0')
// 			return (0);
// 		if (tab[i] != '.' && map[j] == '#')
// 			return (0);
// 		while (tab[i] == '.' && map[j] == '#')
// 		{
// 			i++;
// 			j++;
// 			count++; 
// 		}
// 		j = j + 4 + (spc);
// 		i = i + len + (spc);
// 	}
// 	return (1);
// }

// void	place(char *map, char *tab, char c, int i)
// {
// 	int 	j;
// 	int 	count;
// 	int		len;
// 	int		spc;

// 	j = 0;
// 	count = 0;
// 	len = (int)ft_len(tab);
// 	spc = len - 5;
// 	while (map[j] == '.')
// 	{
// 		j++;
// 		i++;
// 	}
// 	while (map[j] && count < 4)
// 	{
// 		while (map[j] == '#')
// 		{
// 			tab[i] = c;
// 			i++;
// 			j++;
// 			count++;
// 		}
// 		j = j + 4 + (spc);
// 		i = i + len + (spc);
// 	}
// }

int		backtracking(t_tetro *t, char c, char *tab)
{
	int 	i;

	i = 0;
	if (t == NULL)
		return (1);
	while (tab[i])
	{
		if (tab[i] == '.')
		{
			if (can_place(t->map, tab, i) == 1)
			{
				place(t->map, tab, c, i);
				if (backtracking(t->next, (c + 1), tab))
					return (1);
				else
					place(t->map, tab, '.', i);
			}
		}
		i++;
	}
	return (0);
}
