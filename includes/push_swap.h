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
# define MAKE_RANGE 1
# define INVERSE_WEIGHT 1
# define ROT_INS_WEIGHT 1

typedef enum		e_ops
{
	op_id,
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr ,
	too_big,
}					t_ops;

typedef struct		s_tack
{
	int				*stack;
	U int			size;
}					t_tack;

typedef struct		s_stacks
{
	t_tack			a;
	int				score_a;
	t_tack			b;
	int				score_b;
}					t_stacks;

typedef struct		s_node
{
	struct s_node	*parent;
	struct s_node	**desc;
	t_stacks		stacks;
	const t_ops		*ops;
	int				depth;
	int				weight;
}					t_node;

typedef struct		s_flags
{
	char			verbose;
}					t_flags;

typedef struct		s_data
{
	t_node			*start;
	t_flags			flags;
}					t_data;

/*
** parse_input
*/
t_data				parse(char **argv);


/*
** elements
*/
t_tack				rot(t_tack st);
t_tack				rev_rot(t_tack st);
t_tack				swap(t_tack st);
t_tack				copy(t_tack st, int offset);

/*
** operations
*/
t_stacks			id(t_stacks stacks, char free);
t_stacks			pa(t_stacks stacks, char free);
t_stacks			pb(t_stacks stacks, char free);
t_stacks			ra(t_stacks stacks, char free);
t_stacks			rb(t_stacks stacks, char free);
t_stacks			rr(t_stacks stacks, char free);
t_stacks			rra(t_stacks stacks, char free);
t_stacks			rrb(t_stacks stacks, char free);
t_stacks			rrr(t_stacks stacks, char free);
t_stacks			sa(t_stacks stacks, char free);
t_stacks			sb(t_stacks stacks, char free);
t_stacks			ss(t_stacks stacks, char free);

/*
** solver.c
*/
void				solver(t_data data);

/*
** queue.c
*/
void				insert_new(t_node **start, t_node *new);
void				remove_state(t_node **queue, t_node *start, t_node state);
int					dup_state(t_node *start, t_node state);

/*
** node_tools.c
*/
void				free_node(t_node *n);
t_node				*full_pop(t_node *n, t_node **queue);
t_node				*pop_min(t_node **queue);
void				pop(t_node *n, t_node **start);


/*
** op_dispatch.c
*/
void				op_dispatch(t_ops op, t_node node, t_node **root);
void				copy_array(int *new, int *old, int len);

/*
** inversion_score.c
*/
int					inversion_score(int *st, int len, char stck);

#endif
