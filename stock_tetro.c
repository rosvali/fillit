/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:08:23 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/18 17:43:30 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_put_map_in_str(char *buff, int start)
{
	char	*str;

	str = ft_strsub(buff, start, 19);

	str = delete_nl(str);
	tetro_shift_top(str);
	tetro_shift_left(str);
	return (str);
}

void		ft_lstadd_tetro(t_tetro **alst, t_tetro *new)
{
	if (new && alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_tetro		*ft_lstnew_tetro(char *buff, int len)
{
	t_tetro	*tetro;

	if (!(tetro = malloc(sizeof(t_tetro))))
		return (NULL);
	tetro->map = ft_put_map_in_str(buff, len);
	tetro->next = NULL;
	return (tetro);
}

t_tetro		*ft_put_str_in_list(char *buff)
{
	int		start;
	t_tetro	*new;
	t_tetro	*t;

	t = NULL;
	start = 21 * (ft_count_maps(buff) - 1);
	t = ft_lstnew_tetro(buff, start);
	t->next = NULL;
	start -= 21;
	while (start >= 0)
	{
		new = ft_lstnew_tetro(buff, start);
		ft_lstadd_tetro(&t, new);
		start -= 21;
	}
	return (t);
}
