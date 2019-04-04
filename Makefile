# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwatanab <kwatanab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/14 16:20:24 by raguillo          #+#    #+#              #
#    Updated: 2019/04/03 19:34:03 by kwatanab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c\
		checkfile.c\
		check_blocks.c\
		stock_tetro.c\
		backtracking.c\
		map_shifter.c\
		place.c\
		can_place.c\
		final_tab.c\
		free_list.c\
		delete.c

OBJECTS = $(SRCS:.c=.o)

HEAD = fillit.h

LIBRARY = libft/libft.a

all: $(NAME)

$(LIBRARY):
	make -C libft/

$(NAME): $(LIBRARY) $(SRCS) $(HEAD)
	gcc $(SRCS) -I $(HEAD) $(LIBRARY) -Wall -Wextra -Werror -o $(NAME)

clean:
	rm -f $(OBJECTS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
