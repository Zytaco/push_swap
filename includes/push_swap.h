/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 13:20:21 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 13:20:21 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../c_libraries/libft/includes/libft.h"

/*
** longest subsequence defines
*/
# define IND(x) (x + subseq.offset) % arr.len

# define SIZE(x) (x + arr.len - subseq.start) % arr.len
# define SIZE_CMP_A SIZE(arr.stack[IND(j)]) < SIZE(arr.stack[IND(i)])
# define SIZE_CMP_B SIZE(arr.stack[IND(j)]) > SIZE(arr.stack[IND(i)])
# define SIZE_CMP stack == 'a' ? SIZE_CMP_A : SIZE_CMP_B

typedef struct		s_array
{
	int				*stack;
	int				len;
}					t_array;

typedef struct		s_flags
{
	char			v;
}					t_flags;

typedef struct		s_solution
{
	char			*solution;
}					t_solution;

typedef struct		s_data
{
	t_array			a;
	t_array			b;
	t_flags			flags;
	t_solution		*sol;
}					t_data;

typedef struct		s_subseq
{
	int				*steps;
	int				*prev;
	int				offset;
	int				start;
}					t_subseq;

/*
** display.c
*/
void				display_array(t_array a, char *name);

/*
** solver.c
*/
void				solver(t_data data);
int					is_ordered(t_array a, char stack);
int					ordered(t_array a, char stack);

/*
** parse_input.c
*/
void				put_int_in_stack(t_array a, int argc, char **argv);
int					count_ints_store_flags(t_data *data, int argc,
																char **argv);

/*
** array_help.c
*/
void				free_t_array(t_array *a);
t_array				*new_array(int len);
int					get_pos(t_array *a, int x);

/*
** normalise_stack.c
*/
int					get_min_pos(t_array a);
int					get_max_pos(t_array a);
void				normalise_stack(t_array a);

/*
** longest_subsequence.c
*/
t_array				*find_longest_subseq(t_array arr, char stack);

/*
** operations.
*/
void				add_operation(t_data *data, char *op);
void				pa(t_data *data, int bool);
void				pb(t_data *data, int bool);
void				ra(t_data *data, int bool);
void				rb(t_data *data, int bool);
void				rr(t_data *data, int bool);
void				rra(t_data *data, int bool);
void				rrb(t_data *data, int bool);
void				rrr(t_data *data, int bool);
void				sa(t_data *data, int bool);
void				sb(t_data *data, int bool);
void				ss(t_data *data, int bool);

#endif
