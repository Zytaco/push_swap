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

void	solver(t_data data)
{
	t_node	*root;
	t_node	*current;
	t_ops	op;
	int		cycles;

	cycles = 0;
	root = new_node(data.a, data.b, ft_strdup(""), 0);
	if (data.flags.v)
		display_node(*root);
	current = root;
	while (current->weight > 0)
	{
		cycles++;
		current = pop_min(&root);
		if (data.flags.v)
			display_node(*current);
		op = op_sa;
		while (op <= op_rrr)
		{
			op_dispatch(op, *current, &root, current->instr);
			op++;
		}
	}
	ft_putstr("DONE DONE DONE DONE DONE DONE DONE DONE DONE DONE cycles: ");
	ft_putnbr(cycles);
	ft_putstr(" | instructions: ");
	ft_putnbr(current->n_instr);
	ft_putchar('\n');
	// ft_putstr(current->instr);
}
