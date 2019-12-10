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

t_node				*alt_pa(t_node node, t_array a, t_array b)
{
	t_array *new_a;
	t_array *new_b;
	char	*new_instr;

	if (b.len < 1)
		return (NULL);
	new_a = new_array(a.len + 1);
	new_b = new_array(b.len - 1);
	if (!new_a || !new_b)
		ft_error("array not allocated");




	new_a->stack[0] = b.stack[0];
	copy_array(new_a->stack + 1, a.stack, a.len);
	copy_array(new_b->stack, b.stack + 1, b.len - 1);





	new_instr = ft_strjoin(node.instr, "pa\n");
	if (!new_instr)
		ft_error("alt_pa() failed to malloc");
	return (new_node(new_a, new_b, new_instr, node.n_instr + 1));
}
