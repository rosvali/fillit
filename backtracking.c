/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:49:01 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/25 20:03:07 by kwatanab         ###   ########.fr       */
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
		// printf("%d\n", count);
	}
	return (tab);
}

int		can_place(char *map, char *tab, int i)
{
	int	count;
	int j;

	count = 0;
	j = 0;
	while (count < 4)
	{
		if (tab[i] == '\0' || map[j] == '\0')
			return(0);
		else if (tab[i] != '.' && map[j] == '#')
			return (0);
		else if (tab[i] == '.' && map[j] == '#')
		{
			count++;
			i++;
			j++;
		}
	}
	return (1);
}

void		place(char *map, char *tab, char c, int i)
{
	int 	j;
	int 	count;

	j = 0;
	count = 0;
	while (tab[i] && count <= 4)
	{
		if (tab[i] == '.' && map[j] == '#')
		{
			tab[i] = c;
			count++;
			j++;
			i++;
		}
		else
		{
			tab[i] = map[j];
			i++;
			j++;
		}
	}
}

int		backtracking(t_tetro *t, char c, char *tab)
{
	int		count;
	int 	i;

	count = 4;
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
