:wq/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:12:47 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/06 19:07:37 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_readfile(int fd)
{
	int				ret;
	static char		buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
		buff[ret] = '\0';
	return (buff);
}

int		ft_checksize(char *buff)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (buff[i] != '\0')
	{
		while (x < 4 && buff[i] != '\0')
		{
			if (buff[i] != '.' && buff[i] != '#')
				return (0);
			i++;	
			x++;
		}
		if (buff[i] == '\n')
		{
			x = 0;
			y++;
			i++;
		}
		else
			return (0);
		if (y == 4 && buff[i] == '\n')
		{
			y = 0;
			x = 0;
			i++;	
		}
	}
	return (1);
}

int		ft_countmaps(char *buff)
{
	int	maps;
	int	count;
	int	i;
	
	maps = 0;
	count = 0;
	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			count++;
		if (count == 4)
		{
			maps++;
			count = 0;
		}
		i++;
	}
	return (maps);
}

