/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 12:08:49 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/12 12:08:49 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_ints(t_tack st)
{
	U int i;

	i = 0;
	while (i < st.size)
	{
		ft_printf("%12d ", st.stack[i]);
		i++;
	}
}

void		display_node(t_node node)
{
	ft_printf("Score: %d  |  Operations: ", node.weight);
	display_ops(node.ops);
	ft_printf("\na length: %d   a score: %d\n", node.stacks.a.size,
														node.stacks.score_a);
	print_ints(node.stacks.a);
	ft_printf("\nb length: %d   b score: %d\n", node.stacks.b.size,
														node.stacks.score_b);
	print_ints(node.stacks.b);
	ft_putchar('\n');
}

void		display_input_error(char *arg, t_flags *flags)
{
	ft_printf("ERROR at: %s\n", arg);
	flags->help = 1;
}

void		display_ops(const t_ops *ops)
{
	const char	*names[13] = {"id", "sa", "sb", "ss", "pa", "pb", "ra", "rb",
										"rr", "rra", "rrb", "rrr", "too_big"};
	size_t		i;

	if (!ops)
		return ;
	i = 0;
	while (op_id <= ops[i] && ops[i] < too_big)
	{
		if (i != 0)
			ft_putchar(' ');
		if (ops[i] != op_id)
			ft_putstr(names[ops[i]]);
		i++;
	}
}

void		push_swap_help(void)
{
	ft_putstr("usage: ./push_swap ");
	ft_putendl("[-v] [-s] [-r <int>] [-h] [<int> <int>...]\n");
	ft_putendl("-v:    Verbose mode.");
	ft_putendl("-r:    random mode, random integers will be generated as");
	ft_putendl("       input and put in the position of the -r flag.");
	ft_putendl("       The amount of integers will equal the following int.");
	ft_putendl("       Note: The following int must be positive");
	ft_putendl("       Note: The generated ints will be displayed unless ");
	ft_putendl("       the -s tag is active.");
	ft_putendl("-s:    Silent mode, silences -r and disables -v tag.");
	ft_putendl("-h:    Help. Displays usage.");
	ft_putendl("-d:    Destinations. Displays destinations with stacks.");
	ft_putendl("-p:    Points. Displays points with stacks.");
	ft_printf("<int>:  Any number between %d and %d\n", INT32_MIN, INT32_MAX);
}
