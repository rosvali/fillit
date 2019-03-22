/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:12:47 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/12 14:15:22 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
	int		i;
	char	*str;

	map = ft_count_maps(buff);
	y = 0;
	i = 0;
	while (y < map)
	{
		str = ft_strsub(buff, i, 20);
		if (ft_check_connection_blocs(str) == 0)
			return (0);
		else
		{
			ft_strclr(str);
			free(str);
			i = i + 21;
			y++;
		}
	}
	return (1);
}

char	*ft_read_file(int fd)
{
	int				ret;
	static char		buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
		buff[ret] = '\0';
	return (buff);
}

int		ft_check_file(char *buff)
{
	if (ft_check_maps(buff) == 0)
		return (0);
	if (ft_check_blocs(buff) == 0)
		return (0);
	if (ft_check_all_co_maps(buff) == 0)
		return (0);
	return (1);
}
