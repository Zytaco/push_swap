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

OPERATIONS	 =	elements id pa pb ra rb rr rra rrb rrr sa sb ss

SHARED_FILES =	display normalise_stack parse_input\
				$(OPERATIONS:%=operations/%)

SRCS_CHECK	 =	main

SRCS_PUSH	 =	get_state_score inversion_score main make_node node_tools \
				op_dispatch solver

PUSH_C		 =	$(SHARED_FILES:%=shared/%.c)\
				$(SRCS_PUSH:%=srcs_push/%.c)

PUSH_O		 =	$(PUSH_C:.c=.o)

CHECK_C		 =	$(SHARED_FILES:%=shared/%.c)\
				$(SRCS_CHECK:%=srcs_check/%.c)

CHECK_O		 =	$(CHECK_C:.c=.o)

LIBFT		 =	./c_libraries/libft/libft.a
LIBDIR		 =	./c_libraries/libft/

FLAGS		 =	-g -Wall -Wextra -Werror

all			:$(NAME1) $(NAME2)

$(NAME1)	:$(PUSH_O) $(LIBFT)
				@ gcc $(FLAGS) -o $@ $(PUSH_O) -L $(LIBDIR) -lft
				@ echo "\033[32mPUSH_SWAP READY\033[0m"

$(NAME2)	:$(CHECK_O) $(LIBFT)
				@ gcc $(FLAGS) -o $@ $(CHECK_O) -L $(LIBDIR) -lft
				@ echo "\033[32mCHECKER READY\033[0m"

$(LIBFT)	:
	 			@ make -C $(LIBDIR)

%.o			:%.c includes/push_swap.h
				@ gcc $(FLAGS) $< -c -o $@

clean		:
				@ make clean -C $(LIBDIR); \
				rm -f $(SHARED_FILES:%=shared/%.o) \
				$(SRCS_PUSH:%=srcs_push/%.o) \
				$(SRCS_CHECK:%=srcs_check/%.o)
				@ echo "\033[33mCLEANED\033[0m"

fclean		:
				@ make clean -C $(LIBDIR); \
				rm -f $(SHARED_FILES:%=shared/%.o) \
				$(SRCS_PUSH:%=srcs_push/%.o) \
				$(SRCS_CHECK:%=srcs_check/%.o) \
				$(NAME1) $(NAME2)
				@ echo "\033[91mFULL CLEANED\033[0m"
				
re			:fclean all

.PHONY		:clean fclean all re
