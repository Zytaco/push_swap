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

static t_node	*best_desc_exceptions(t_node *best, t_node *current)
{
	if (!best || best->weight >= current->weight)
	{
		if (best && best->weight != INT32_MAX)
			current->weight = best->weight + 1;
		else
			current->weight++;
		if (current->parent)
			return (current->parent);
	}
	return (best);
}

/*
** Returns the best descendant unless current is as bad as the best desc.
** In that case it may return the parent if it exists. 
*/

t_node			*best_desc(const t_node *current, const int max_depth)
{
	const int	depth;
	t_node		*best;
	t_ops		op;

	best = NULL;
	if (max_depth <= 0)
		return (NULL);
	if (!current->desc)
		current->desc = ft_memalloc(sizeof(t_node*) * ((size_t)too_big + 1));
	op = 0;
	while (op < too_big)
	{
		if (!current->desc[op])
			current->desc[op] = make_node(current, op);
		if (max_depth > 1)
			best_desc(current->desc[op], max_depth - 1);
		if (!best || best->weight > current->desc[op]->weight)
			best = current->desc[op];
		op++;
	}
	best = best_desc_exceptions(best, current);
	return (best);
}

ops			*solver(t_data data)
{
	t_node	*current;
	t_ops	op;
	int		cycle;

	cycle = 0;
	current = data.start;
	if (data.flags.v)
	{
		ft_putstr("INPUT:\n");
		display_node(current);
	}
	while (!solved(current->stacks))
	{
		current = best_desc(current, MAKE_RANGE);
		if (flags.v)
			display_node(current);
		cycle++;
	}
	if (flags.v)
	{
		ft_putstr("DONE DONE DONE DONE DONE DONE DONE DONE DONE DONE cycles: ");
		ft_putnbr(cycles);
		ft_putstr(" | instructions: ");
		ft_putnbr(current->n_instr);
		ft_putchar('\n');
	}
	return (current->ops);
}
