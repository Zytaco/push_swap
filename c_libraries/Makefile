#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/31 12:38:38 by jheeresm      #+#    #+#                  #
#    Updated: 2019/10/31 12:38:39 by jheeresm      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

LIBFT	=	libft.a
LIBSORT	=	libsort.a

all: $(LIBFT) $(LIBSORT)
	@ echo "\033[36mALL LIBS: COMPILED\033[0m"

$(LIBFT):
	@make -C ./libft/
	@cp ./libft/libft.a ./


$(LIBSORT):
	@make -C ./libsort/
	@cp libsort/libsort.a ./

clean:
	@make clean -C ./libft
	@make clean -C ./libsort
	@ echo "\033[33mALL LIBS: CLEANED\033[0m"

fclean:
	@make fclean -C ./libft
	@make fclean -C ./libsort
	@rm -f ./libft.a
	@rm -f ./libsort.a
	@ echo "\033[91mALL LIBS: FULL CLEANED\033[0m"

re:	 fclean all
