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

	root = new_node(data.a, data.b, ft_strdup(""), 0);
	current = root;
	while (current->weight > 0)
	{
		current = pop_min(&root);
		// display_node(*current);
		op = op_sa;
		while (op <= op_rrr)
		{
			op_dispatch(op, *current, &root, current->instr);
			op++;
		}
	}
	ft_putstr("DONE DONE DONE DONE DONE DONE DONE DONE DONE DONE DONE DONE DONE DONE \n");
	display_node(*current);
}
