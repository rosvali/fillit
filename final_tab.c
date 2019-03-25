/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:42:44 by kwatanab          #+#    #+#             */
/*   Updated: 2019/03/25 18:39:16 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*create_final_tab(int *count)
{
	char	*tab;
	int		i;

	i = 0;
	while (ft_sqrt(*count) == 0)
		*count = *count + 1;
	if (!(tab = malloc(sizeof(char) * (*count + 1))))
		return (0);
	while (i < *count)
	{
		tab[i] = '.';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*delete_nl(char *map)
{
	char	*new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new_map = malloc(sizeof(char) * ((int)ft_strlen(map) - 3) + 1)))
		return(NULL);
	while (map[i])
	{
		if (map[i] == '\n')
			i++;
		else
		{
			new_map[j] = map[i];
			i++;
			j++;
		}
	}
	new_map[j] = '\0';
	return (new_map);
}

size_t		ft_len(char *tab)
{
	size_t len;

	len = ft_strlen(tab);
	// printf("len dans ft_len = %zu\n", len);
	len = ft_sqrt(len);
	return (len);
}
