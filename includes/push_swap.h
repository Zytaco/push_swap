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
# include <sys/time.h>

/*
	Let's say that input size = N. And that all input ints (n) are normalised
	so that for all n it holds that 0 <= n < N.

	The space can be described as the following 0 is in one of N locations,
	1 is in one of N - 1 locations 2 is in one of N - 2 locations etc.

	Example:
	Input is 10 3 -100 0 -101 which is normalised to 4 3 1 2 0
	Representation of input is [4][2][3][1][0]
	Swap : 0 and 1 are swapped -> [4][2][3][0][1]
	Rot: 
*/
/*
** longest subsequence defines
*/
# define MAKE_RANGE 1
# define INVERSE_WEIGHT 1
# define ROT_INS_WEIGHT 1
# define NO 0
# define YES 1
# define CHILD_WEIGHT (current->desc[op - 1]->weight)
# define CHILD (current->desc[op - 1])
# define BACKTRACK_WEIGHT 0

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
	op_rrr,
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
	int				score;
}					t_node;

typedef struct		s_flags
{
	char			verbose;
	char			random;
	int				n_random;
	char			normalize;
	char			help;
}					t_flags;

typedef struct		s_qnode
{
	struct s_qnode	*next;
	t_node			*node;
	int				weight;
}					t_qnode;

typedef struct		s_data
{
	t_node			*start;
	t_flags			flags;
	int				max_depth;
	int				smallest;
	int				biggest;
	t_qnode			*queue;
}					t_data;

typedef struct		s_queue
{
	struct s_queue	*first;
	struct s_queue	*last;
	U int			size;
}					t_queue;


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
** display
*/
void				display_node(t_node node);
void				display_input_error(char *arg, t_flags *flags);
void				display_ops(const t_ops *ops);
void				push_swap_help(void);

/*
** duplicate check
*/
int					duplicate_check(t_stacks stacks);

/*
** normalize stack
*/
t_tack				normalize(t_tack st);
int					get_lowest(int *st, int len);
int					get_highest(int *st, int len);
int					count_smaller(int x, t_tack st);
int					count_bigger(int x, t_tack st);
int					get_pos(int x, t_tack st);

/*
** parse_input
*/
void				parse(char **argv, t_data *data);

/*
** get weight
*/
void				get_weight(t_node *node, t_data data);

/*
** queue.c
*/
void				add_to_queue(t_node *node, t_qnode *queue, t_data *data);
t_node				*next_from_queue(t_data *data);

/*
** solver.c
*/
const t_ops			*solver(t_data data);


/*
** make node
*/
t_node				*make_node(t_node *parent, t_ops op, t_flags flags, t_data *data);

/*
** node_tools.c
*/
void				free_node(t_node **n);
void				free_all_nodes(t_node *node);


/*
** op_dispatch.c
*/
t_stacks			op_dispatch(t_ops op, t_stacks stacks, char free);
void				copy_array(int *new, int *old, int len);

/*
** descendants
*/
t_node				*best_desc(t_node *current, const int depth,
												t_flags flags, t_data *data);

/*
** inversion_score.c
*/
int					rot_distance(int dist, int len);
int					inversion_score(t_tack st, char stack);
int					new_inversion_score(t_tack st, char stack);
int					swap_score(t_tack st, char stck);
t_stacks			stacks_cuts(t_stacks stacks);

#endif
