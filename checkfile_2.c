/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 17:12:13 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/08 17:12:15 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_maps_2(char *buff, int *i, int *x, int *y)
{
	if (buff[*i] == '\n' && buff[*i + 1] != '\0')
	{
		*x = 0;
		*y = *y + 1;
		*i = *i + 1;
	}
	else if (buff[*i] == '\0' && *x == 4)
		return (1);
	else
		return (0);
	if (*y == 4 && buff[*i] == '\n')
	{
		*y = 0;
		*x = 0;
		*i = *i + 1;
	}
	return (2);
}

void	ft_check_connection_blocs_2(char **tab, int *x, int *y, int *count)
{
	if (tab[*y][*x] == '#')
	{
		if (*y != 0)
		{
			if (tab[*y - 1][*x] != '\0' && tab[*y - 1][*x] == '#')
				*count = *count + 1;
		}
		if (*y != 3)
		{
			if (tab[*y + 1][*x] == '#' && tab[*y + 1][*x])
				*count = *count + 1;
		}
		if (*x != 0)
		{
			if (tab[*y][*x - 1] == '#' && tab[*y][*x - 1])
				*count = *count + 1;
		}
		if (*x != 3)
		{
			if (tab[*y][*x + 1] == '#' && tab[*y][*x + 1])
				*count = *count + 1;
		}
	}
}

int		ft_check_maps(char *buff)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (buff[i] != '\0')
	{
		while (buff[i] != '\0' && x < 4)
		{
			if (buff[i] != '.' && buff[i] != '#')
				return (0);
			i++;
			x++;
		}
		if (ft_check_maps_2(buff, &i, &x, &y) == 0)
			return (0);
		else if (ft_check_maps_2(buff, &i, &x, &y) == 1)
			return (1);
	}
	return (1);
}

int		ft_check_connection_blocs(char *buff)
{
	char	**tab;
	int		x;
	int		y;
	int		count;

	tab = ft_strsplit(buff, '\n');
	x = 0;
	y = 0;
	count = 0;
	while (tab[y])
	{
		while (tab[y][x] != '\0')
		{
			ft_check_connection_blocs_2(tab, &x, &y, &count);
			x++;
		}
		x = 0;
		y++;
	}
	if (count < 6)
		return (0);
	return (1);
}
