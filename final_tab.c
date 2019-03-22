/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:42:44 by kwatanab          #+#    #+#             */
/*   Updated: 2019/03/21 16:54:18 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_final_tab(int *count)
{
	char	*tab;
	int		i;

	i = 0;
	while (ft_sqrt(*count) == 0)
		*count = *count + 1;
	if (!(tab = malloc(sizeof(char) * (*count + 1))))
		return (0);
	while (i < (*count + 1))
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
