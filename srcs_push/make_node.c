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
	while (ops && ops[i] != overflow)
		i++;
	new = ft_memalloc(sizeof(t_ops) * (i + 2));
	new[i + 1] = overflow;
	while (ops && i > 0)
	{
		i--;
		new[i + j] = ops[i];
	}
	return (new);
}

int				exception(t_ops last, t_ops op)
{
	if (
	(last == op_sa && (op == op_sa || op == op_ss)) ||
	(last == op_sb && (op == op_sb || op == op_ss)) ||
	(last == op_pb && op == op_pa) ||
	(last == op_pa && op == op_pb) ||
	(last == op_ra && op == op_rra) ||
	(last == op_rb && op == op_rrb) ||
	(last == op_rr && (op == op_rrb || op == op_rra || op == op_rrr)) ||
	(last == op_rra && op == op_ra) ||
	(last == op_rrb && op == op_rb) ||
	(last == op_rrr && (op == op_rb || op == op_ra || op == op_rr)) ||
	)
		return (1);
	return (0);
}

static void		pessimism_test(t_node *parent, int child_weight)
{
	if (parent && parent->weight > child_weight + 1)
	{
		ft_putstr("PESSIMISM\n");
		parent->weight = child_weight + 1;
		pessimism_test(parent->parent, parent->weight);
	}
}

t_node			*make_node(t_node *parent, t_ops op)
{
	t_node *const new = ft_memalloc(sizeof(t_node));

	if (parent->depth > 0 && exception(parent->ops[parent->depth - 1], op))
	{
		new->weight = INT32_MAX;
		return (new);
	}
	new->parent = parent
	new->desc = NULL;
	new->stacks = op_dispatch(op, );
	new->ops = add_op(parent->ops, op);
	new->depth = parent->depth + 1;
	current->desc[op]->weight = get_weight(current->desc[op]);
	pessimism_test(parent, new->weight);
	return (new);
}
