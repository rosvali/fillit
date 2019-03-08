/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:12:47 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/07 16:08:14 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_maps(char *buff)
{
	int	maps;
	int	count;
	int	i;

	maps = 0;
	count = 1;
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			count++;
		if (count == 5)
		{
			maps++;
			count = 0;
		}
		i++;
	}
	maps++;
	return (maps);
}

int		ft_check_blocs(char *buff)
{
	int		i;
	int		j;
	int		diese;

	i = 0;
	j = 0;
	diese = 0;
	while (buff[i])
	{
		while (buff[i] && j < 21)
		{
			if (buff[i] == '#')
				diese++;
			i++;
			j++;
		}
		if (diese == 4)
		{
			j = 0;
			diese = 0;
		}
		else
			return (0);
	}
	return (1);
}

int		ft_check_all_co_maps(char *buff)
{
	int		map;
	int		y;
	char	*str;
	int		i;

	map = ft_count_maps(buff);
	y = 0;
	i = 0;
	while (y < map)
	{
		if ()
	}
	return (1);
}
