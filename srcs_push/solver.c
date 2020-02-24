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

int				solved(t_stacks stacks)
{
	size_t i;

	if (stacks.b.size != 0)
		return (0);
	i = 0;
	while (i + 1 < stacks.a.size)
	{
		if (stacks.a.stack[i] + 1 != stacks.a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
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
		best_desc(current, 0, data.flags, &data);
		ft_putstr("\n\nHeyyy\n\n");
		current = next_from_queue(&data);
		cycle++;
		// if (cycle >= MAKE_RANGE)
		// 	ft_error("Too many cycles");
		if (data.flags.verbose)
		{
			ft_printf("Cycle: %d\n", cycle);
			display_node(*current);
		}
	}
	if (data.flags.verbose)
		ft_printf("DONE DONE\ncycles: %d  depth: %d\n", cycle, current->depth);
	return (current->ops);
}
