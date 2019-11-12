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

# define PART_SIZE 5
# define M(x) ft_modulo(x, data.a->len + data.b->len)

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
	t_array			*a;
	t_array			*b;
	char			*solution;
	t_flags			flags;
	t_solution		*sol;
}					t_data;

t_data				*parse_input(t_data data, int argc, char **argv);
void				add_operation(t_data data, char *op);
t_array				*new_array(int len);
void				free_t_array(t_array *a);
t_array				*get_longest_subseq(t_data data, t_array arr);
void				rotations(t_data data, int a_rot, int b_rot, int rot_both);
void				rev_rotations(t_data data, int a_rot, int b_rot,
																int rot_both);
void				display(t_data data);
void				display_help(void);
void				solver(t_data data);

/*
** operations.
*/
void				pa(t_data data, int bool);
void				pb(t_data data, int bool);
void				ra(t_data data, int bool);
void				rb(t_data data, int bool);
void				rr(t_data data, int bool);
void				rra(t_data data, int bool);
void				rrb(t_data data, int bool);
void				rrr(t_data data, int bool);
void				sa(t_data data, int bool);
void				sb(t_data data, int bool);
void				ss(t_data data, int bool);

#endif
