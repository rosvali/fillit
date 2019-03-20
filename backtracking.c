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

#include "fillit.h"
#include <stdio.h>

int		*ft_blocs_coords(char *str)
{
	int i;
	int j;
	int *tab;

	i = 0;
	j = 0;
	if (!(tab = malloc(sizeof(char) * 4)))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			tab[j] = i;
			printf("%d\n", tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}

// char	*ft_place_tetro_in_str(char *map, char *str, char c)
// {
// 	int 	i;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	while (count < 4)
// 	{
// 		while (map[i] != '\n' && str[i] != '\n')
// 		{
// 			if (map[i] == '#' && str[i] != '.')
// 				str[i] = c;
// 			else
// 				//effacer le tetro
// 		}
// 	}
// }