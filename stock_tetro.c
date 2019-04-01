/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:08:23 by raguillo          #+#    #+#             */
/*   Updated: 2019/04/01 19:07:25 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*split_and_move(char *buff, int start)
{
	char	*str;

	if (!(str = ft_strsub(buff, start, 19)))
		return (NULL);
	str = delete_nl(str);
	tetro_shift_top(str);
	tetro_shift_left(str);
	return (str);
}

void		lstadd_tetro(t_tetro **alst, t_tetro *new)
{
	if (new && alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_tetro		*lstnew_tetro(char *buff, int len)
{
	t_tetro	*tetro;

	if (!(tetro = malloc(sizeof(t_tetro))))
		return (NULL);
	if (!(tetro->map = split_and_move(buff, len)))
		return (NULL);
	tetro->next = NULL;
	return (tetro);
}

t_tetro		*create_tetro(char *buff)
{
	int		start;
	t_tetro	*new;
	t_tetro	*t;

	t = NULL;
	start = 21 * (count_maps(buff) - 1);
	t = lstnew_tetro(buff, start);
	t->next = NULL;
	start -= 21;
	while (start >= 0)
	{
		if (!(new = lstnew_tetro(buff, start)))
			return (NULL);
		lstadd_tetro(&t, new);
		start -= 21;
	}
	return (t);
}

void		free_lst(t_tetro *t)
{
	while (t)
	{
		free(t->map);
		t = t->next;
	}
	t = NULL;
}
