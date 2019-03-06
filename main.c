/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:02:31 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/06 19:08:45 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int				fd;
	int				ret;
	char			*map;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		map = ft_readfile(fd);
		ret = ft_checksize(map);
		printf("la fonction retourne : %d\n", ret);
		printf("Nombre de map = %d\n", ft_countmaps(map));
	}
	return (0);
}
