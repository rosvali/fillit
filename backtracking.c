/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:38:43 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/03 19:26:56 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		backtracking_main(t_tetro *t, char c, char *tab, int i)
{
	if (ft_strlen(tab) <= 16)
	{
		if (can_place(t->map, tab, i) == 1)
		{
			place(t->map, tab, c, i);
			return (1);
		}
	}
	else
	{
		if (can_place_sup(t->map, tab, i) == 1)
		{
			place_sup(t->map, tab, c, i);
			return (1);
		}
	}
	return (0);
}

int		backtracking(t_tetro *t, char c, char *tab)
{
	int		i;

	i = 0;
	if (t == NULL)
		return (1);
	while (tab[i])
	{
		if ((tab[i] != '.' && tab[i + 1] && tab[i + 1] != '.' && tab[i + 2] &&
		tab[i + 2] == '.') || (tab[i] != '.' && tab[i + 1] && tab[i + 1] == '.')
		|| tab[i] == '.')
		{
			if (backtracking_main(t, c, tab, i) == 1)
			{
				if (backtracking(t->next, (c + 1), tab))
					return (1);
				if (ft_strlen(tab) <= 16)
					delete_block(t->map, tab, '.', i);
				else
					delete_block_sup(t->map, tab, '.', i);
			}
		}
		i++;
	}
	return (0);
}
