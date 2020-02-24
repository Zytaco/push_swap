/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:11:52 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 15:11:53 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// static t_stacks	get_ordered(t_stacks stacks)
// {
// 	t_stacks	ordered;
// 	size_t		i;

// 	ordered.a.size = stacks.a.size;
// 	ordered.a.stack = ft_memalloc(sizeof(int) * ordered.a.size);
// 	i = 0;
// 	while (i < ordered.a.size)
// 	{
// 		ordered.a.stack[count_smaller(stacks.a.stack[i], stacks.a)] =
// 															stacks.a.stack[i];
// 		i++;
// 	}
// 	return (ordered);
// }

static t_data	init_data(void)
{
	t_data data;

	data.flags.verbose = 0;
	data.flags.random = 0;
	data.flags.n_random = 0;
	data.flags.normalize = 0;
	data.flags.help = 0;
	data.start = ft_memalloc(sizeof(t_node));
	data.start->depth = 0;
	data.start->desc = NULL;
	data.start->ops = NULL;
	data.start->parent = NULL;
	data.start->stacks.a.size = 0;
	data.start->stacks.a.stack = NULL;
	data.start->stacks.score_a = INT32_MAX;
	data.start->stacks.b.size = 0;
	data.start->stacks.b.stack = NULL;
	data.start->stacks.score_b = INT32_MAX;
	data.start->weight = INT32_MAX;
	data.start->score = INT32_MAX;
	data.max_depth = MAKE_RANGE;
	data.queue = NULL;
	return (data);
}

int				main(int argc, char **argv)
{
	t_data		data;

	if (argc <= 1)
		return (1);
	if (MAKE_RANGE < 1)
		ft_error("Please increase MAKE_RANGE");
	data = init_data();
	parse(argv, &data);
	if (data.flags.help)
	{
		push_swap_help();
		return (1);
	}
	duplicate_check(data.start->stacks);
	data.start->stacks.a = normalize(data.start->stacks.a);
	data.smallest = get_lowest(data.start->stacks.a.stack,
												data.start->stacks.a.size);
	data.biggest = get_highest(data.start->stacks.a.stack,
												data.start->stacks.a.size);
	get_weight(data.start, data);
	display_ops(solver(data));
	return (1);
}
