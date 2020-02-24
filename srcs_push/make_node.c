/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_node.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:02:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/05 15:02:07 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ops			*add_op(const t_ops *ops, const t_ops add)
{
	int		i;
	t_ops	*new;

	i = 0;
	while (ops && ops[i] != too_big)
		i++;
	new = ft_memalloc(sizeof(t_ops) * (i + 2));
	new[i + 1] = too_big;
	new[i] = add;
	while (ops && i > 0)
	{
		i--;
		new[i] = ops[i];
	}
	return (new);
}

int				exception(t_ops last, t_ops op, int size_a, int size_b)
{
	return (
	(size_a < 2 && (op == op_sa || op == op_ss || op == op_ra || op == op_rr
	|| op == op_rra || op == op_rrr)) ||
	(size_b < 2 && (op == op_sb || op == op_ss || op == op_rb || op == op_rr
	|| op == op_rrb || op == op_rrr)) ||
	(size_a == 0 && op == op_pb) ||
	(size_b == 0 && op == op_pa) ||
	(last == op_sa && (op == op_sa || op == op_ss)) ||
	(last == op_sb && (op == op_sb || op == op_ss)) ||
	(last == op_pb && op == op_pa) ||
	(last == op_pa && op == op_pb) ||
	(last == op_ra && (op == op_rra || op == op_rrr)) ||
	(last == op_rb && (op == op_rrb || op == op_rrr)) ||
	(last == op_rr && (op == op_rrb || op == op_rra || op == op_rrr)) ||
	(last == op_rra && (op == op_ra || op == op_rr)) ||
	(last == op_rrb && (op == op_rb || op == op_rr)) ||
	(last == op_rrr && (op == op_rb || op == op_ra || op == op_rr))
	);
}

static int		pessimism_test(t_node *parent, t_node n)
{
	if (parent && n.weight != INT32_MAX && parent->weight > n.weight + 1)
	{
		parent->weight = n.weight + 1;
		pessimism_test(parent->parent, *parent);
		return (1);
	}
	return (0);
}

t_node			*make_node(t_node *parent, t_ops op, t_flags flags, t_data *data)
{
	t_node *const new = ft_memalloc(sizeof(t_node));

	if (parent && parent->depth > 0 &&
	exception(parent->ops[parent->depth - 1], op,
								parent->stacks.a.size, parent->stacks.b.size))
		new->weight = INT32_MAX;
	else
	{
		new->parent = parent;
		new->desc = NULL;
		new->depth = parent->depth + 1;
		new->ops = add_op(parent->ops, op);
		new->stacks = op_dispatch(op, parent->stacks, NO);
		new->stacks.score_a = 0;
		new->stacks.score_b = 0;
		get_weight(new, *data);
		new->score = new->weight + new->depth;
	}
	if (pessimism_test(parent, *new) && flags.verbose)
	{
		// ft_putstr("PESSIMISM\n");
		// display_node(*new);
	}
	add_to_queue(new, data->queue, data);
	// if (!duplicate_check(parent->stacks) || !duplicate_check(new->stacks))
	// {
	// 	display_node(*new);
	// 	ft_error("BAD OPERATION");
	// }
	return (new);
}
