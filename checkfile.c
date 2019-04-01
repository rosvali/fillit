/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:12:47 by raguillo          #+#    #+#             */
/*   Updated: 2019/04/01 19:51:07 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		count_maps(char *buff)
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
		if (count == 5 && buff[i + 1])
		{
			maps++;
			count = 0;
		}
		i++;
	}
	maps++;
	return (maps);
}

int		check_blocs(char *buff)
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

int		split_maps(char *buff)
{
	int		map;
	int		y;
	int		i;
	char	*str;

	map = count_maps(buff);
	y = 0;
	i = 0;
	while (y < map)
	{
		if (!(str = ft_strsub(buff, i, 20)))
			return (0);
		if (!check_tetro(str))
			return (0);
		ft_strclr(str);
		free(str);
		i = i + 21;
		y++;
	}
	return (1);
}

char	*read_file(int fd)
{
	int				ret;
	static char		buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
		buff[ret] = '\0';
	return (buff);
}

int		checking(char *buff)
{
	if (check_maps(buff) == 0)
		return (0);
	if (check_blocs(buff) == 0)
		return (0);
	if (split_maps(buff) == 0)
		return (0);
	return (1);
}
