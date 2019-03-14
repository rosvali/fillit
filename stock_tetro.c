/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 18:08:23 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/08 18:08:25 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*ft_put_splitter(char *buff)
{
	int i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n' && buff[i - 1] == '\n')
			buff[i] = '3';
		i++;
	}
	return (buff);
}

char		**ft_put_map_in_tab(char *buff, int start)
{
	char	*str;
	char	**tab;

	str = ft_strsub(buff, start, 20);

	tab = ft_strsplit(str, '\n');
	return (tab);
}

t_tetro		*ft_create_tetro(char *buff)
{
	int		start;
	int		i;
	t_tetro	*t;
	t_tetro	*tmp;
	char	**tab;

	t = NULL;
	start = 0;
	i = 0;
	while (i < (ft_count_maps(buff) - 1))
	{
		printf("i = %d\n", i);
		printf("start = %d\n", start);
		tab = ft_put_map_in_tab(buff, start);
		start += 21;
		i++;
		if (!(t = malloc(sizeof(t_tetro))))
		{
			ft_lstdel(t);
			return (NULL);
		}
		t->map = tab;
		ft_printtab(t->map);
		t->next = t;
	}
	printf("start = %d\n", start);
	ft_put_map_in_tab(buff, start);
	start = start + 20;
	printf("%d\n", start);
	if (!(t = malloc(sizeof(t_tetro))))
		return (NULL);
	t->map = tab;
	ft_printtab(t->map);
	t->next = NULL;
	return (t);
}
