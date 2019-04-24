#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 14:53:22 by jheeresm      #+#    #+#                  #
#    Updated: 2019/04/22 14:53:22 by jheeresm      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME1 = checker

SRC1 = check_if_int.c checker_main.c operate.c operate_helper.c get_next_line.c

OBJ1 = $(SRC1:.c=.o) libft/libft.a

FLG = -Wall -Werror -Wextra

all: $(NAME1)

$(NAME1): $(SRC1) libft/srcs/ft_*.c libft/libft.a
	gcc -c $(FLG) $(SRC1)
	gcc  $(FLG) $(OBJ1) -o $(NAME1)

libft/libft.a:
	make -C libft/ libft.a

clean:
	make -C libft/ clean
	rm -f $(OBJ1)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME1)

re: fclean all
	make -C libft/ re

cleanmake: all clean
