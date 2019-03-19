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
#include <stdio.h>

char		*ft_put_map_in_tab(char *buff, int start)
{
	char	*str;

	str = ft_strsub(buff, start, 20);
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
	else
		tetro->map = ft_put_map_in_tab(buff, len);
	tetro->next = NULL;
	return (tetro);
}

t_tetro		*ft_put_tab_in_list(char *buff)
{
	int		len;
	t_tetro	*new;
	t_tetro	*t;

	t = NULL;
	len = 21 * (ft_count_maps(buff) - 1);
	t = ft_lstnew_tetro(buff, len);
	t->next = NULL;
	len -= 21;
	while (len >= 0)
	{
		new = ft_lstnew_tetro(buff, len);
		ft_lstadd_tetro(&t, new);
		len -= 21;
	}
	return (t);
}
