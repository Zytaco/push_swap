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
		insert_new(&root, alt_pa(*current));
		insert_new(&root, alt_pb(*current));
		insert_new(&root, alt_ra(*current));
		insert_new(&root, alt_rb(*current));
		insert_new(&root, alt_rr(*current));
		insert_new(&root, alt_rra(*current));
		insert_new(&root, alt_rrb(*current));
		insert_new(&root, alt_rrr(*current));
		insert_new(&root, alt_sa(*current));
		insert_new(&root, alt_sb(*current));
		insert_new(&root, alt_ss(*current));
		current = pop_min(&root);
	}
	ft_putstr(current->instr);
}

