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

CHECKER = checker_main.c get_next_line.c

SHARED = check_and_make.c operate.c operate_helper.c

LIBFT1 = ft_atoi.c ft_strdel.c ft_strjoin.c ft_strcpy.c ft_strlen.c
LIBFT1 += ft_strcmp.c ft_strnchr.c ft_strnew.c

SRC1 = $(CHECKER:%=check_files/%)
SRC1 += $(SHARED:%=shared/%)
SRC1 += $(LIBFT1:%=libft/srcs/%)

OBJ1 = $(CHECKER:.c=.o)
OBJ1 += $(SHARED:.c=.o)
OBJ1 += $(LIBFT1:.c=.o)

NAME2 = push_swap

OPERATE = push_swap.c

LIBFT2 = ft_strnew.c ft_strjoin.c ft_atoi.c ft_strcmp.c

SRC2 = $(OPERATE:%=operate_files/%)
SRC2 += $(SHARED:%=shared/%)
SRC2 += $(LIBFT2:%=libft/srcs/%)

OBJ2 = $(OPERATE:.c=.o)
OBJ2 += $(SHARED:.c=.o)
OBJ2 += $(LIBFT2:.c=.o)

FLG = -Wall -Werror -Wextra -g

all: $(NAME1) $(NAME2)

$(NAME1): $(SRC1)
	gcc -c $(FLG) $(SRC1)
	gcc  $(FLG) $(OBJ1) -o $(NAME1)

$(NAME2): $(SRC2)
	gcc -c $(FLG) $(SRC2)
	gcc  $(FLG) $(OBJ2) -o $(NAME2)

clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all

cleanmake: all clean
