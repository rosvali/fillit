/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:02:31 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/07 16:06:45 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

char	*ft_read_file(int fd)
{
	int				ret;
	static char		buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
		buff[ret] = '\0';
	return (buff);
}

int		main(int argc, char **argv)
{
	int				fd;
	char			*map;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	map = ft_read_file(fd);
	printf("ft_checkmaps retourne : %d\n", ft_check_maps(map));
	printf("ft_checkblocs retourne : %d\n", ft_check_blocs(map));
	printf("ft_check_all_co_maps retourne : %d\n", ft_check_all_co_maps(map));
	return (0);
}