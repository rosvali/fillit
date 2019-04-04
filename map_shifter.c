/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shifter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:41:34 by kwatanab          #+#    #+#             */
/*   Updated: 2019/04/03 19:29:13 by kwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetro_shift(char *piece, size_t n)
{
	size_t i;

	i = 0;
	while (i < 16)
	{
		piece[i] = (i + n >= 16 ? '.' : piece[i + n]);
		++i;
	}
}

void	tetro_shift_left(char *piece)
{
	while (piece[0] == '.' && piece[4] == '.'
		&& piece[8] == '.' && piece[12] == '.')
		tetro_shift(piece, 1);
}

void	tetro_shift_top(char *piece)
{
	while (piece[0] == '.' && piece[1] == '.'
		&& piece[2] == '.' && piece[3] == '.')
		tetro_shift(piece, 4);
}
