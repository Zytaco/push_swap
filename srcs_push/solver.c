/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 17:52:17 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/14 17:52:17 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		solved(t_stacks stacks)
{
	size_t i;

	if (stacks.b.size > 0)
		return (0);
	i = 0;
	while (i + 1 < stacks.a.size)
	{
		if (stacks.a.stack[i] >= stacks.a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static t_node	*best_desc_exceptions(t_node *best, t_node *current)
{
	if (!best)
	{
		if (current->parent)
			return (current->parent);
		else
			ft_error("UNSOLVABLE!");
	}
	if (current->weight < best->weight)
	{
		if (best->weight != INT32_MAX)
			current->weight = best->weight + 1;
		else
			current->weight++;
		if (current->parent)
			return (current->parent);
		else
			return (current);
	}
	else
		return (best);
}

/*
** Returns the best descendant unless current is as bad as the best desc.
** In that case it may return the parent if it exists. 
*/

static t_node		*best_desc(t_node *current, const int max_depth, t_flags flags)
{
	t_node		*best;
	t_ops		op;

	best = NULL;
	if (max_depth <= 0)
		return (current);
	if (!current->desc)
		current->desc = ft_memalloc(sizeof(t_node*) * ((size_t)too_big));
	op = op_id + 1;
	while (op < too_big)
	{
		if (!current->desc[op])
			current->desc[op] = make_node(current, op, flags);
		if (max_depth > 1 && current->desc[op]->weight != INT32_MAX)
			best_desc(current->desc[op], max_depth - 1, flags);
		if (!best || best->weight > current->desc[op]->weight)
			best = current->desc[op];
		op++;
	}
	best = best_desc_exceptions(best, current);
	return (best);
}

const t_ops		*solver(t_data data)
{
	t_node	*current;
	int		cycle;

	cycle = 0;
	current = data.start;
	if (data.flags.verbose)
	{
		ft_printf("Cycle: %d\n", cycle);
		ft_putstr("INPUT:\n");
		display_node(*current);
	}
	while (!solved(current->stacks))
	{
		current = best_desc(current, MAKE_RANGE, data.flags);
		cycle++;
		if (data.flags.verbose)
		{
			ft_printf("Cycle: %d\n", cycle);
			display_node(*current);
		}
		if (cycle >= 1000)
			ft_error("Too many cycles");
	}
	if (data.flags.verbose)
		ft_printf("DONE DONE\ncycles: %d  depth: %d\n", cycle, current->depth);
	return (current->ops);
}
