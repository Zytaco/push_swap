/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alt_super_swap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 14:28:43 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/06 14:28:43 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node				*alt_sup_swap_a(t_node node, t_array a, t_array b)
{
	t_array *new_a;
	t_array *new_b;
	char	*new_instr;
	int		i;

	if (a.len < 6)
		return (NULL);
	new_a = new_array(a.len - 2);
	new_b = new_array(b.len + 2);
	if (!new_a || !new_b)
		ft_error("array not allocated");
	new_a->stack[0] = a.stack[3];
	new_a->stack[1] = a.stack[2];
	i = 2;
	while (i < new_a->len)
	{
		new_a->stack[i] = a.stack[i + 2];
		i++;
	}
	new_b->stack[0] = a.stack[0];
	new_b->stack[1] = a.stack[1];
	i = 0;
	while (i < b.len)
	{
		new_b->stack[i + 2] = b.stack[i];
		i++;
	}
	new_instr = ft_strjoin(node.instr, "pb\npb\nss\n");
	if (!new_instr)
		ft_error("alt_pa() failed to malloc");
	return (new_node(new_a, new_b, new_instr, 3));
}

t_node				*alt_sup_swap_b(t_node node, t_array a, t_array b)
{
	t_array *new_a;
	t_array *new_b;
	char	*new_instr;
	int		i;

	if (b.len < 4)
		return (NULL);
	new_a = new_array(a.len + 2);
	new_b = new_array(b.len - 2);
	if (!new_a || !new_b)
		ft_error("array not allocated");
	new_a->stack[0] = a.stack[0];
	new_a->stack[1] = a.stack[1];
	i = 0;
	while (i < a.len)
	{
		new_a->stack[i + 2] = a.stack[i];
		i++;
	}
	new_b->stack[0] = a.stack[3];
	new_b->stack[1] = a.stack[2];
	i = 2;
	while (i < new_b->len)
	{
		new_b->stack[i + 2] = b.stack[i + 2];
		i++;
	}
	new_instr = ft_strjoin(node.instr, "pa\npa\nss\n");
	if (!new_instr)
		ft_error("alt_pa() failed to malloc");
	return (new_node(new_a, new_b, new_instr, 3));
}
