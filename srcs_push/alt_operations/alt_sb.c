/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:28 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:28 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node				*alt_sb(t_node node)
{
	t_array *new_a;
	t_array *new_b;
	int		i;

	if (node.b->len <= 1)
		return (NULL);
	new_a = new_array(node.a->len);
	new_b = new_array(node.b->len);
	i = 0;
	while (i < new_a->len)
	{
		new_a->stack[i] = node.a->stack[i];
		i++;
	}
	if (new_a->len > 1)
	{
		new_b->stack[0] = node.b->stack[1];
		new_b->stack[1] = node.b->stack[0];
	}
	i = 2;
	while (i < new_b->len)
	{
		new_b->stack[i] = node.b->stack[i];
		i++;
	}
	return (new_node(new_a, new_b, ft_strjoin(node.instr, "sb\n"),
															node.n_instr + 1));
}
