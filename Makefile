# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 16:20:24 by raguillo          #+#    #+#              #
#    Updated: 2019/03/14 16:20:26 by raguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c\
		checkfile.c\
		checkfile_2.c\
		stock_tetro.c

OBJECTS = $(SRCS:.c=.o)

HEAD = fillit.h

LIBRARY = libft/libft.a

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	make -C libft/

$(NAME): $(SRCS) $(HEAD)
	gcc $(SRCS) -I $(HEAD) $(LIBRARY) -Wall -Wextra -Werror -g -o $(NAME)

clean:
	rm -f $(OBJECTS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
