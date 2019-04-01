/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:47:45 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/01 18:57:04 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetrodel(t_tetro **alst)
{
	if (*alst)
	{
		tetrodel(&((*alst)->next));
		tetrodelone(alst);
	}
}

void	tetrodelone(t_tetro **alst)
{
	if (*alst)
		ft_memdel((void **)&(*alst)->map);
	ft_memdel((void **)alst);
}
