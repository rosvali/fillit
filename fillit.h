/* ******************************** ****************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:13:09 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/08 18:06:24 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 600
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>

typedef struct		s_tetro
{
	char			*map;
	struct s_tetro	*next;
}					t_tetro;

/*
** Fonctions qui check la validité du fichier
** checkfile.c checkfile_2.c
*/

char				*ft_read_file(int fd);

int					ft_check_file(char *buff);

int					ft_check_maps(char *buff);

int					ft_check_maps_2(char *buff, int *i, int *x, int *y);

int					ft_count_maps(char *buff);

int					ft_check_blocs(char *buff);

int					ft_check_connection_blocs(char *buff);

void				ft_check_connection_blocs_2(char **tab, int *x, int *y,
					int *count);

int					ft_check_all_co_maps(char *buff);

/*
** Fonctions de stockage des tetrominoes
** stock_tetro.c
*/

char				*ft_put_map_in_tab(char *buff, int start);

t_tetro				*ft_put_tab_in_list(char *buff);

void				ft_lstadd_tetro(t_tetro **alst, t_tetro *new);

t_tetro				*ft_lstnew_tetro(char *buff, int len);

/*
** Fonctions du backtracking
*/

char				**ft_create_final_tab(int len);

/*
** Fonctions d'affichage
** test.c
*/

void				ft_print_put_map_in_tab(char *map);

void				ft_print_create_tetro(t_tetro *t);
#endif
