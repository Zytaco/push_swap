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
	op_rrr = 10
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

typedef struct		s_solution
{
	char			*solution;
}					t_solution;

typedef struct		s_data
{
	t_array			*a;
	t_array			*b;
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

typedef struct		s_node
{
	struct s_node	*parent;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*child;
	int				descendants;
	char			*instr;
	int				n_instr;
	t_array			*a;
	t_array			*b;
	int				weight;
}					t_node;

/*
** display.c
*/
void				display_array(t_array a, char *name);
void				display_solution(char *solution);

/*
** merge_split
*/
void				split(t_array *dump, t_data *data, char stck);
void				merge(t_array dump, t_data *data, char stck);

/*
** solver.c
*/
void				solver(t_data data);
int					is_ordered(t_array a, char stack);
int					ordered(t_array a, char stack);

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
int					get_min_pos(t_array a);
int					get_max_pos(t_array a);
void				normalisestck(t_array a);

/*
** get_state_score.c
*/
void				get_state_score(t_node *node);

/*
** operations
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

/*
** alt_operations
*/
t_node				*alt_pa(t_node node);
t_node				*alt_pb(t_node node);
t_node				*alt_ra(t_node node);
t_node				*alt_rb(t_node node);
t_node				*alt_rr(t_node node);
t_node				*alt_rra(t_node node);
t_node				*alt_rrb(t_node node);
t_node				*alt_rrr(t_node node);
t_node				*alt_sa(t_node node);
t_node				*alt_sb(t_node node);
t_node				*alt_ss(t_node node);

/*
** alt_operations
*/
t_node				*new_node(t_array *a, t_array *b, char *instr,
																int n_instr);

/*
** queue.c
*/
void				insert_new(t_node **start, t_node *new);
t_node				*pop_min(t_node **queue);
t_node				*new_node(t_array *a, t_array *b, char *instr, int n_instr);

/*
** op_dispatch.c
*/
void				op_dispatch(t_ops op, t_node node, t_node **root, char *instr);

#endif
