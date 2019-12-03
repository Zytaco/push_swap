/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:50 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:51 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node				*alt_rb(t_node node)
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
	if (new_b->len > 0)
		new_b->stack[new_b->len - 1] = node.b->stack[0];
	i = 1;
	while (i < new_b->len)
	{
		new_b->stack[i - 1] = node.b->stack[i];
		i++;
	}
	return (new_node(new_a, new_b, ft_strjoin(node.instr, "rb\n"),
															node.n_instr + 1));
}
