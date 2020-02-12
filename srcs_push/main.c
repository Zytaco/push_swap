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

static int		duplicate_check(t_tack a)
{
	size_t i;
	size_t j;

	i = 0;
	while (i + 1 < a.size)
	{
		j = i + 1;
		while (j < a.size)
		{
			if (a.stack[i] == a.stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				ordered(t_tack st)
{
	size_t i;
	size_t j;

	i = 0;
	while (i + 1 < st.size)
	{
		j = 0;
		while (j < st.size)
		{
			if (st.stack[i] == st.stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
	duplicate_check(data.start->stacks.a);
	if (data.flags.normalize)
		data.start->stacks.a = normalize(data.start->stacks.a);
	get_weight(data.start);
	display_ops(solver(data));
	return (1);
}
