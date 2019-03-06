/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:35:33 by raguillo          #+#    #+#             */
/*   Updated: 2018/12/05 17:34:06 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_factorial(int nb)
{
	int		fac;

	if (nb > 12 || nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	fac = nb * ft_recursive_factorial(nb - 1);
	return (fac);
}
