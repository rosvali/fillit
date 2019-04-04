/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:42:44 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/03 19:28:31 by kwatanab         ###   ########.fr       */
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
	if (!(tab = malloc(*count + 1)))
		return (0);
	while (i < *count)
	{
		tab[i] = '.';
		i++;
	}
	tab[i] = '\0';
	i = 0;
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
		return (NULL);
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
	free(map);
	new_map[j] = '\0';
	return (new_map);
}

size_t	tab_len(char *tab)
{
	size_t len;

	len = ft_strlen(tab);
	len = ft_sqrt(len);
	return (len);
}

void	print_tab(char *tab, size_t len)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (tab[i])
	{
		ft_putchar(tab[i]);
		i++;
		j++;
		if (j == (int)len)
		{
			ft_putchar('\n');
			j = 0;
		}
	}
}
