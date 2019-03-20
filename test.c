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
	while (i < ft_count_maps(map))
	{
		ft_putstr(ft_put_map_in_str(map, start));
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
	map = ft_read_file(fd);
	//printf("ft_count_maps retourne : %d\n", ft_count_maps(map));

/* Fonctions qui check la validité du fichier */

	// printf("ft_checkmaps retourne : %d\n", ft_check_maps(map));
	// printf("ft_checkblocs retourne : %d\n", ft_check_blocs(map));
	// printf("ft_check_connection_blocs : %d\n", ft_check_connection_blocs(map));
	// printf("ft_check_all_co_maps retourne : %d\n", ft_check_all_co_maps(map));

/* Fonctions qui vont permettre le stockage des tetriminoes */

	//ft_print_put_map_in_tab(map);
	//ft_print_put_map_in_tab(map);
	t = ft_put_str_in_list(map);
	// ft_print_create_tetro(t);

/* Fonctions du backtracking */

	//ft_print_put_map_in_tab(map);
	ft_blocs_coords(t->map);
	return (0);
}