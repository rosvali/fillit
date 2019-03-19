/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:02:31 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/13 18:22:31 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*buff;
	t_tetro *tetro;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file.fillit\n", 35);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	buff = ft_read_file(fd);
	if (ft_check_file(buff) == 0)
	{
		write (1, "error\n", 6);
		return (0);
	}
	tetro = ft_put_tab_in_list(buff);
	while (tetro)
	{
		ft_printtab(tetro->map);
		tetro = tetro->next;
	}
	close(fd);
	return (0);
}
