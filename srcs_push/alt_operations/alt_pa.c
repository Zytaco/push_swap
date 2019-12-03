/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:39 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:39 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node				*alt_pa(t_node node)
{
	t_array *new_a;
	t_array *new_b;
	int		i;

	if (node.b->len > 0)
	{
		new_a = new_array(node.a->len + 1);
		new_b = new_array(node.b->len - 1);
		new_a->stack[0] = node.b->stack[0];
		i = 1;
		while (i < new_a->len)
		{
			new_a->stack[i] = node.a->stack[i - 1];
			i++;
		}
		i = 0;
		while (i < new_b->len)
		{
			new_b->stack[i] = node.b->stack[i + 1];
			i++;
		}
		return (new_node(new_a, new_b, ft_strjoin(node.instr, "pa\n"),
															node.n_instr + 1));
	}
	return (NULL);
}
