/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:02:31 by raguillo          #+#    #+#             */
/*   Updated: 2019/04/01 19:22:03 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <stdio.h>

void		solver(char *buff)
{
	t_tetro *tetro;
	char	*tab;
	size_t	len;

	tetro = create_tetro(buff);
	tab = grow_and_solve(tetro);
	tetrodel(&tetro);
	len = tab_len(tab);
	print_tab(tab, len);
	free(tab);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file.fillit\n", 35);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	buff = read_file(fd);
	if (checking(buff) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	solver(buff);
	close(fd);
	return (0);
}
