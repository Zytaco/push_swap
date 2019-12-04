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
	char	*temp;

	temp = ft_strdup("");
	root = new_node(data.a, data.b, temp, 0);
	free(temp);
	current = root;
	while (current->weight > 0)
	{
		op_dispatch(op_sa, *current, &root, current->instr);
		op_dispatch(op_sb, *current, &root, current->instr);
		op_dispatch(op_ss, *current, &root, current->instr);
		op_dispatch(op_pa, *current, &root, current->instr);
		op_dispatch(op_pb, *current, &root, current->instr);
		op_dispatch(op_ra, *current, &root, current->instr);
		op_dispatch(op_rb, *current, &root, current->instr);
		op_dispatch(op_rr, *current, &root, current->instr);
		op_dispatch(op_rra, *current, &root, current->instr);
		op_dispatch(op_rrb, *current, &root, current->instr);
		op_dispatch(op_rrr, *current, &root, current->instr);
		current = pop_min(&root);
	}
	ft_putstr(current->instr);
}
