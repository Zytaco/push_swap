/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alt_pushback_b.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/07 15:29:13 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/07 15:29:14 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** 8 1 2 3 4
** 5 6 7
**
**
** 1 2 3 4
** 5 6 7 8
*/

t_node				*alt_pushback_b(t_node node, t_array a, t_array b)
{
	t_array *new_a;
	t_array *new_b;
	char	*new_instr;
	int		i;

	if (b.len < 1)
		return (NULL);
	new_a = new_array(a.len - 1);
	new_b = new_array(b.len + 1);
	if (!new_a || !new_b)
		ft_error("array not allocated");
	i = 1;
	while (i < a.len)
	{
		new_a->stack[i - 1] = a.stack[i];
		i++;
	}
	new_b->stack[b.len] = a.stack[0];
	i = 0;
	while (i < b.len)
	{
		new_b->stack[i] = b.stack[i];
		i++;
	}
	new_instr = ft_strjoin(node.instr, "pa\nrb\n");
	if (!new_instr)
		ft_error("alt_pa() failed to malloc");
	return (new_node(new_a, new_b, new_instr, 2));
}
