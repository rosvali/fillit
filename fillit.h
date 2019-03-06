/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:13:09 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/06 19:03:29 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 1000
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

char	*ft_readfile(int fd);
int		ft_checksize(char *buff);
int		ft_countmaps(char *buff);

#endif
