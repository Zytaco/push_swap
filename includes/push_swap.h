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
# define TRY_OUT_RANGE 1
# define INVERSE_WEIGHT 1
# define ROT_INS_WEIGHT 1

typedef enum		e_ops
{
	too_small = -1,
	op_sa = 0,
	op_sb = 1,
	op_ss = 2,
	op_pa = 3,
	op_pb = 4,
	op_ra = 5,
	op_rb = 6,
	op_rr = 7,
	op_rra = 8,
	op_rrb = 9,
	op_rrr = 10,
	op_sup_swap_a = 11,
	op_sup_swap_b = 12,
	op_sup_rot_a = 13,
	op_sup_rot_b = 14,
	op_pushback_a = 15,
	op_pushback_b = 16,
	too_big = 17
}					t_ops;

typedef struct		s_array
{
	int				*stack;
	int				len;
}					t_array;

typedef struct		s_flags
{
	char			v;
}					t_flags;

typedef struct		s_data
{
	t_array			*a;
	t_array			*b;
	t_flags			flags;
}					t_data;

typedef struct		s_subseq
{
	int				*steps;
	int				*prev;
	int				offset;
	int				start;
}					t_subseq;

typedef struct		s_node
{
	struct s_node	*parent;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*child;
	int				members;
	char			*instr;
	int				n_instr;
	t_array			*a;
	t_array			*b;
	int				score_a;
	int				score_b;
	int				weight;
}					t_node;

/*
** display.c
*/
void				display_array(t_array a, char *name);
void				display_solution(char *solution);
void				display_node(t_node node);
void				display_forest(t_node *root);

/*
** merge_split
*/
void				split(t_array *dump, t_data *data, char stck);
void				merge(t_array dump, t_data *data, char stck);

/*
** solver.c
*/
void				solver(t_data data);

/*
** parse_input.c
*/
void				put_int_instck(t_array a, int argc, char **argv);
int					count_ints_store_flags(t_data *data, int argc,
																char **argv);

/*
** array_help.c
*/
void				free_t_array(t_array *a);
t_array				*new_array(int len);
int					get_pos(t_array a, int x);

/*
** normalisestck.c
*/
int					get_min_pos(int *st, int len);
int					get_max_pos(int *st, int len);
void				normalisestck(t_array a);

/*
** get_state_score.c
*/
void				get_state_score(t_node *node, t_array a, t_array b);

/*
** operations
*/
void				add_operation(t_data *data, char *op);
void				pa(t_data *data);
void				pb(t_data *data);
void				ra(t_data *data);
void				rb(t_data *data);
void				rr(t_data *data);
void				rra(t_data *data);
void				rrb(t_data *data);
void				rrr(t_data *data);
void				sa(t_data *data);
void				sb(t_data *data);
void				ss(t_data *data);

/*
** alt_operations
*/
t_node				*alt_pa(t_node node, t_array a, t_array b);
t_node				*alt_pb(t_node node, t_array a, t_array b);
t_node				*alt_ra(t_node node, t_array a, t_array b);
t_node				*alt_rb(t_node node, t_array a, t_array b);
t_node				*alt_rr(t_node node, t_array a, t_array b);
t_node				*alt_rra(t_node node, t_array a, t_array b);
t_node				*alt_rrb(t_node node, t_array a, t_array b);
t_node				*alt_rrr(t_node node, t_array a, t_array b);
t_node				*alt_sa(t_node node, t_array a, t_array b);
t_node				*alt_sb(t_node node, t_array a, t_array b);
t_node				*alt_ss(t_node node, t_array a, t_array b);
t_node				*alt_sup_swap_a(t_node node, t_array a, t_array b);
t_node				*alt_sup_swap_b(t_node node, t_array a, t_array b);
t_node				*alt_sup_rot_a(t_node node, t_array a, t_array b);
t_node				*alt_sup_rot_b(t_node node, t_array a, t_array b);
t_node				*alt_pushback_a(t_node node, t_array a, t_array b);
t_node				*alt_pushback_b(t_node node, t_array a, t_array b);

/*
** alt_operations
*/
t_node				*new_node(t_array *a, t_array *b, char *instr,
																int n_instr);

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
t_node				*new_node(t_array *a, t_array *b, char *instr, int n_instr);
void				pop(t_node *n, t_node **start);


/*
** op_dispatch.c
*/
void				op_dispatch(t_ops op, t_node node, t_node **root, char *instr);
void				copy_array(int *new, int *old, int len);

/*
** inversion_score.c
*/
int					inversion_score(int *st, int len, char stck);
int					inversion_score_a(t_array arr);
int					inversion_score_b(t_array arr);

#endif
