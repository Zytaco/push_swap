#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 12:38:38 by jheeresm      #+#    #+#                  #
#    Updated: 2019/12/16 15:50:50 by jheeresm      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME =		libft.a

CC = 		gcc

CFLAGS =	-Wall -Wextra -Werror -c

CHAR-FUNCTIONS	=	isalnum isalpha isascii isdigit isint isprint iswhitespace \
					tolower toupper

LIST-FUNCTIONS	=	lstadd lstaddend lstaddlast lstdel lstdelone lstiter \
					lstlen lstmap lstnew

MATH-FUNCTIONS	=	abs count_digits modulo nroot power primes pythagoras sqrt\
					max min bcd lcm

MEM-FUNCTIONS	= 	bzero free memalloc memccpy memchr memcmp memcpy memdel \
					memmove memset

PUT-FUNCTIONS	=	putchar_fd	putchar	putendl_fd putendl	putnbr_fd	putnbr \
					putnbrbase_fd putnbrbase	putstr_fd	putstr\
					putunbr_fd	putunbr	putunbrbase_fd	putunbrbase

STR-FUNCTIONS	=	skip_whitespace stradd strapp skipstr\
					strcat strchr strclr strcmp strcount strcpy strdel strdup \
					strequ strfsplit strins striter striteri strjoin strlcat strlen \
					strlower strmap strmapi strncat strncmp strncpy strndup\
					strnequ strnew strnstr strprep strrchr strsplit strstr \
					strsub strtoupper strtrim strrepeat strupper

MISC-FUNCTIONS	=	atoi atoullbase basetonbr error free_array get_next_line \
					itoa itobase utoa utobase

FT_PRINTF_SUB	=	char flags float int num perc pointer str uint
FT_PRINTF		=	$(FT_PRINTF_SUB:%=printf_%) printf
FT_PRINTF_H		=	srcs/ft_printf/ft_printf.h

SOURCES			=	$(CHAR-FUNCTIONS:%=srcs/char-functions/ft_%) \
					$(LIST-FUNCTIONS:%=srcs/list-functions/ft_%) \
					$(MATH-FUNCTIONS:%=srcs/math-functions/ft_%) \
					$(MEM-FUNCTIONS:%=srcs/mem-functions/ft_%) \
					$(PUT-FUNCTIONS:%=srcs/put-functions/ft_%) \
					$(STR-FUNCTIONS:%=srcs/str-functions/ft_%) \
					$(MISC-FUNCTIONS:%=srcs/misc-functions/ft_%) \
					$(FT_PRINTF:%=srcs/ft_printf/ft_%)

CFILE			=	$(SOURCES:%=%.c)

OBJECTS			=	$(SOURCES:%=%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(FT_PRINTF_H)
		@ ar rc $(NAME) $(OBJECTS)
		@ ranlib $(NAME)
		@ echo "\033[36mLIBFT: COMPILED\033[0m"

srcs/ft_printf/%.o: srcs/ft_printf%.c $(FT_PRINTF_H)
		@ $(CC) $(CFLAGS) $< -o $@

%.o: %.c
		@ $(CC) $(CFLAGS) $< -o $@

clean:
		@ rm -f $(OBJECTS)
		@ echo "\033[33mLIBFT: CLEANED\033[0m"

fclean:
		@ rm -f $(NAME)
		@ rm -f $(OBJECTS)
		@ echo "\033[91mLIBFT: FULL CLEANED\033[0m"

re:	 fclean all

test: $(NAME) test.c
		@ clear
		@ rm -f a.out
		@ rm -f test
		@ echo "redoing" > test; 
		@ rm -f test
		@ gcc test.c libft.a
		@ ./a.out > test
