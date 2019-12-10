/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrb.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:05:04 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:05:04 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node				*alt_rrb(t_node node, t_array a, t_array b)
{
	t_array *new_a;
	t_array *new_b;
	char	*new_instr;

	if (b.len < 2)
		return (NULL);
	new_a = new_array(a.len);
	new_b = new_array(b.len);
	if (!new_a || !new_b)
		ft_error("array not allocated");
	copy_array(new_a->stack, a.stack, a.len);
	new_b->stack[0] = b.stack[b.len - 1];
	copy_array(new_b->stack + 1, b.stack, b.len - 1);
	new_instr = ft_strjoin(node.instr, "rrb\n");
	if (!new_instr)
		ft_error("alt_pa() failed to malloc");
	return (new_node(new_a, new_b, new_instr, node.n_instr + 1));
}
