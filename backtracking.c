/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:49:01 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/19 13:49:40 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

char	**ft_create_final_tab(int len)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *)* len + 1);
	while (j < len)
	{
		tab[j] = malloc(sizeof(char)* len + 1);
		while (i < len)
		{
			tab[j][i] = '.';
			i++;
		}
		tab[j][i] = '\0';
		j++;
		i = 0;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_place_tetro(t_tetro *t)
{
	int		i;

	i = 0;
	while (t->map)
	{
		
	}
}

int		ft_checkcanplace(char **tab)
{

	if tab
}