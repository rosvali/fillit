/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_place.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <raguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:36:34 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/02 19:25:12 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		can_place_2(char *map, char *tab, int *i, t_var *var)
{
	while (*i < (int)ft_strlen(tab) &&
	tab[*i] && map[var->j] && var->j < var->len)
	{
		if (tab[*i] == '.' && map[var->j] == '#')
		{
			if (((*i) + 1) % (int)tab_len(tab) == 0 && map[var->j + 1] == '#')
				return (0);
			var->count++;
			if (var->count == 4)
				return (1);
		}
		(*i)++;
		var->j++;
	}
	var->j += var->diff;
	var->len += var->diff + var->len;
	var->k++;
	return (2);
}

int		can_place(char *map, char *tab, int i)
{
	t_var	var;
	int		ret;

	var.len = (int)tab_len(tab);
	var.count = 0;
	var.j = 0;
	var.k = 0;
	var.diff = 4 - var.len;
	while (i < (int)ft_strlen(tab) &&
		var.k < (int)tab_len(tab) && var.len <= 16)
	{
		ret = can_place_2(map, tab, &i, &var);
		if (ret == 0)
			return (0);
		if (ret == 1)
			return (1);
	}
	return (0);
}

int		can_place_sup_2(char *map, char *tab, int *i, t_var *var)
{
	while (*i < (int)ft_strlen(tab) && var->lim < 4)
	{
		if (tab[*i] == '.' && map[var->j] == '#')
		{
			if ((*i + 1) % (int)tab_len(tab) == 0 && map[var->j + 1] == '#')
				return (0);
			var->count++;
			if (var->count == 4)
				return (1);
		}
		*i = *i + 1;
		var->j++;
		var->lim++;
	}
	return (2);
}

int		can_place_sup(char *map, char *tab, int i)
{
	t_var	var;
	int		ret;

	var.len = 4;
	var.count = 0;
	var.j = 0;
	var.k = 0;
	var.lim = 0;
	while (i < (int)ft_strlen(tab) &&
		var.k < 4 && var.len <= (int)ft_strlen(tab))
	{
		ret = can_place_sup_2(map, tab, &i, &var);
		if (ret == 0)
			return (0);
		if (ret == 1)
			return (1);
		i += (int)tab_len(tab) - 4;
		var.len += (int)tab_len(tab) - 4 + 4;
		var.k++;
		var.lim = 0;
	}
	return (0);
}
