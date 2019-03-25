/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:02:31 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/25 18:37:08 by kwatanab         ###   ########.fr       */
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
	char	*tab;
	size_t	len;
	int		i;
	int		j;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file.fillit\n", 35);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	buff = ft_read_file(fd);
	if (ft_check_file(buff) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	tetro = ft_put_str_in_list(buff);
	tab = grow_and_solve(tetro);
	len = ft_len(tab);
	j = 0;
	i = 0;
	while (tab[i] != '\0')
	{
		ft_putchar(tab[i]);
		i++;
		j++;
		if (j == (int)len)
		{
			
			ft_putchar('\n');
			j = 0;
		}
	}
	close(fd);
	return (0);
}
