#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jheeresm <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/11 17:22:33 by jheeresm      #+#    #+#                  #
#    Updated: 2019/11/11 17:22:33 by jheeresm      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME1		 =	push_swap

NAME2		 =	checker

CW_NAME		 =	corewar

OPERATIONS	 =	pa pb ra rb rr rra rrb rrr sa sb ss

SHARED_FILES =	add_operation array_help parse_input display\
				$(OPERATIONS:%=operations/%)

SRCS_CHECK	 =	

SRCS_PUSH	 =	longest_subseq main rotations solver

PUSH_C		 =	$(SHARED_FILES:%=shared/%.c)\
				$(SRCS_PUSH:%=srcs_push/%.c)

PUSH_O		 =	$(PUSH_C:.c=.o)

CHECK_C		 =	$(SHARED_FILES:%=shared/%.c)\
				$(SRCS_CHECK:%=srcs_check/%.c)

CHECK_O		 =	$(CHECK_C:.c=.o)

LIBFT		 =	c_libraries/libft/libft.a
LIBDIR		 =	./c_libraries/libft/

FLAGS		 =	-g -Wall -Wextra -Werror

all : $(NAME1) $(NAME2)

$(NAME1)	:$(PUSH_O) $(LIBFT)
				@ gcc $(FLAGS) -o $@ $(PUSH_O) -L . $(LIBFT)
				@ echo "\033[32mPUSH_SWAP READY\033[0m"

$(NAME2)	:$(CHECK_O) $(LIBFT)
				@ gcc $(FLAGS) -o $@ $(CHECK_O) -L . $(LIBFT)
				@ echo "\033[32mCHECKER READY\033[0m"

$(LIBFT)	:
	 			@ make -C $(LIBDIR)

%.o			:	%.c includes/push_swap.h
					@ gcc $(FLAGS) $< -c -o $@

clean		:
				@ make clean -C $(LIBDIR) \
				@ rm -f $(PUSH_O) \
				@ rm -f $(CHECK_O)

fclean		:
				make fclean -C $(LIBDIR); \
				@ rm -f $(PUSH_O); \
				@ rm -f $(CHECK_O);


re			:fclean all

.PHONY: clean fclean all re
