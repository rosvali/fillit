/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <raguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:02:31 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/29 17:59:01 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*buff;
	t_tetro *tetro;
	char	*tab;
	size_t	len;

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
	tetro = create_tetro(buff);
	tab = grow_and_solve(tetro);
	len = tab_len(tab);
	print_tab(tab, len);
	close(fd);
	return (0);
}
