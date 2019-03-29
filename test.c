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

void	ft_print_put_map_in_str(char *map)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (i < count_maps(map))
	{
		ft_putstr(split_and_move(map, start));
		start += 21;
		i++;
	}
}

void	ft_print_create_tetro(t_tetro *t)
{
	while (t)
	{
		ft_putstr(t->map);
		t = t->next;
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*map;
	int 		i;
	t_tetro		*t;

	i = argc;
	fd = open(argv[1], O_RDONLY);
	map = read_file(fd);
	printf("ft_count_maps retourne : %d\n", count_maps(map));

/* Fonctions qui check la validité du fichier */

	// printf("ft_checkmaps retourne : %d\n", ft_check_maps(map));
	// printf("ft_checkblocs retourne : %d\n", ft_check_blocs(map));
	// printf("ft_check_connection_blocs : %d\n", ft_check_connection_blocs(map));
	// printf("ft_check_all_co_maps retourne : %d\n", ft_check_all_co_maps(map));

/* Fonctions qui vont permettre le stockage des tetriminoes */

	//ft_print_put_map_in_str(map);
	t = create_tetro(map);
	// ft_print_create_tetro(t);
/* Fonctions du backtracking */

	return (0);
}