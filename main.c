/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:02:31 by raguillo          #+#    #+#             */
/*   Updated: 2019/03/07 16:06:45 by raguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char	*ft_read_file(int fd)
{
	int				ret;
	static char		buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
		buff[ret] = '\0';
	return (buff);
}

int		ft_check_file(char *buff)
{
	if (ft_check_maps(buff) == 0)
		return (0);
	if (ft_check_blocs(buff) == 0)
		return (0);
	if (ft_check_all_co_maps(buff) == 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*buff;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file.fillit\n", 50);
		return (0);
	}
	buff = ft_read_file(fd);
	if (ft_check_file(buff) == 0)
		write(1, "error\n", 6);
	close(fd);
	return (0);
}
