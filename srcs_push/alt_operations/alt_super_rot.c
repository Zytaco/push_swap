/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alt_super_rot.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 17:09:35 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/06 17:09:35 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** 4 3 2 1 0
**
** 2 1 0 3 4
*/

t_node				*alt_sup_rot_a(t_node node, t_array a, t_array b)
{
	t_array *new_a;
	t_array *new_b;
	char	*new_instr;
	int		i;

	if (a.len < 4 || get_max_pos(a.stack, a.len) != 0 ||
	get_max_pos(a.stack + 1, a.len - 1) != 0)
		return (NULL);
	new_a = new_array(a.len);
	new_b = new_array(b.len);
	if (!new_a || !new_b)
		ft_error("array not allocated");
	new_a->stack[a.len - 1] = a.stack[0];
	new_a->stack[a.len - 2] = a.stack[1];
	i = 0;
	while (i < a.len - 2)
	{
		new_a->stack[i] = a.stack[i + 2];
		i++;
	}
	i = 0;
	while (i < b.len)
	{
		new_b->stack[i] = b.stack[i];
		i++;
	}
	new_instr = ft_strjoin(node.instr, "sa\nra\nra\n");
	if (!new_instr)
		ft_error("alt_pa() failed to malloc");
	return (new_node(new_a, new_b, new_instr, 3));
}

t_node				*alt_sup_rot_b(t_node node, t_array a, t_array b)
{
	t_array *new_a;
	t_array *new_b;
	char	*new_instr;
	int		i;

	if (b.len < 4 || get_max_pos(b.stack, b.len) != 0 ||
	get_max_pos(b.stack + 1, b.len - 1) != 0)
		return (NULL);
	new_a = new_array(a.len);
	new_b = new_array(b.len);
	if (!new_a || !new_b)
		ft_error("array not allocated");
	new_b->stack[b.len - 1] = b.stack[0];
	new_b->stack[b.len - 2] = b.stack[1];
	i = 0;
	while (i < a.len)
	{
		new_a->stack[i] = a.stack[i];
		i++;
	}
	i = 0;
	while (i < b.len - 2)
	{
		new_b->stack[i] = b.stack[i + 2];
		i++;
	}
	new_instr = ft_strjoin(node.instr, "sb\nrb\nrb\n");
	if (!new_instr)
		ft_error("alt_pa() failed to malloc");
	return (new_node(new_a, new_b, new_instr, 3));
}
