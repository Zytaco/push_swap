/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   descendants.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 15:12:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/14 15:12:07 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void order_desc(t_node **desc)
{
	size_t	i;
	t_node	*temp;

	if (!desc || !desc[0] || !desc[1])
		return ;
	i = 0;
	while (desc[i + 1])
	{
		if (desc[i]->weight > desc[i + 1]->weight)
		{
			temp = desc[i];
			desc[i] = desc[i + 1];
			desc[i + 1] = temp;
			if (i == 0)
				i++;
			else
				i--;
		}
		else
			i++;
	}
}

static void deeper_still(t_node *current, const int depth, t_flags flags, t_data *data)
{
	size_t i;
	t_node **const desc = current->desc;

	order_desc(current->desc);
	if (desc && desc[0]->weight == 0 && depth < data->max_depth)
		data->max_depth = depth;
	if (depth >= data->max_depth)
		return ;
	i = 0;
	while (desc[i] && desc[i]->weight != INT32_MAX)
	{
		best_desc(desc[i], depth, flags, data);
		i++;
	}
	order_desc(current->desc);
}

static t_node	*exceptions(t_node *best_child, t_node *current)
{
	if (!best_child)
	{
		ft_putstr("DEAD END\n");
		if (current->parent)
			return (current->parent);
		ft_error("UNSOLVABLE!");
	}
	if (current->weight <= best_child->weight)
	{
		// ft_putstr("OPTIMISM");
		if (best_child->weight != INT32_MAX)
			current->weight = best_child->weight + 1;
		else if (current->weight != INT32_MAX)
			current->weight++;
	}
	if (current->parent && current->parent->weight < best_child->weight + 2 +
	BACKTRACK_WEIGHT)
		return (current->parent);
	return (best_child);
}

/*
** Returns the best descendant unless current is as bad as the best desc.
** In that case it may return the parent if it exists. 
*/
t_node		*best_desc(t_node *current, const int depth, t_flags flags, t_data *data)
{
	t_node		*best;
	t_ops		op;

	best = NULL;
	if (depth > data->max_depth)
		return (current);
	if (!current->desc)
	{
		current->desc = ft_memalloc(sizeof(t_node*) * ((size_t)too_big));
		op = op_id + 1;
		while (op < too_big)
		{
			CHILD = make_node(current, op, flags, data);
			op++;
		}
	}
	deeper_still(current, depth + 1, flags, data);
	best = current->desc[0];
	best = exceptions(best, current);
	return (best);
}
