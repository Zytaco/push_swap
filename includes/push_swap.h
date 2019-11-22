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
# define REV_IND(x) (x + arr.len - subseq.offset) % arr.len
# define SIZE(x) (x + arr.len - subseq.start) % arr.len

/*
** merge/split defines
*/
# define ARRAY (_stack == 'a' ? data->a : data->b)
# define STACK (_stack == 'a' ? data->a.stack : data->b.stack)
# define LEN (_stack == 'a' ? data->a.len : data->b.len)
# define PUSH (_stack == 'a' ? pb(data, 1) : pa(data, 1))
# define ROTATE (_stack == 'a' ? ra(data, 1) : rb(data, 1))

# define O_ARRAY (_stack == 'b' ? data->a : data->b)
# define O_STACK (_stack == 'b' ? data->a.stack : data->b.stack)
# define O_LEN (_stack == 'b' ? data->a.len : data->b.len)
# define O_PUSH (_stack == 'b' ? pb(data, 1) : pa(data, 1))
# define O_ROTATE (_stack == 'b' ? ra(data, 1) : rb(data, 1))

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
void				display_solution(char *solution);

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
int					get_pos(t_array a, int x);

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
