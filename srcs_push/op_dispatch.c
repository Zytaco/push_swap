/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_dispatch.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:31:45 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/03 16:31:45 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		copy_array(int *new, int *old, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		new[i] = old[i];
		i++;
	}
}

int			prev_check(char *s, t_ops op, t_node node)
{
	if (!(s - 1))
		return (0);
	return
	((node.score_a <= 0 && (op == op_sa || op == op_ss))
	|| (node.score_b <= 0 && (op == op_sb || op == op_ss))
	|| ((op <= op_ss || op == op_sup_rot_a) && ft_strequ(s, "sa\n"))
	|| (((op <= op_ss || op == op_sup_rot_b) && ft_strequ(s, "sb\n"))
	|| (op <= op_ss && ft_strequ(s, "ss\n"))
	|| ((op_pb == op || op_sup_swap_a == op) && ft_strequ(s, "pa\n"))
	|| ((op_pa == op || op_sup_swap_b == op) && ft_strequ(s, "pb\n"))
	|| ((op_rra == op || op_rrr == op) && ft_strequ(s, "\nra\n"))
	|| ((op_rrb == op || op_rrr == op) && ft_strequ(s, "\nrb\n"))
	|| (op_rra <= op && ft_strequ(s, "\nrr\n"))
	|| ((op_ra == op || op_rr == op) && ft_strequ(s, "rra\n"))
	|| ((op_rb == op || op_rr == op) && ft_strequ(s, "rrb\n"))
	|| ((op_ra <= op && op <= op_rr) && ft_strequ(s, "rrr\n"))
	));
}

void		op_dispatch(t_ops op, t_node node, t_node **root, char *instr)
{
	t_node	*(*const f[])(t_node, t_array, t_array) = {
	alt_sa, alt_sb, alt_ss, alt_pa, alt_pb, alt_ra, alt_rb, alt_rr, alt_rra,
	alt_rrb, alt_rrr,
	};
	t_node	*new;

	if (node.instr && node.instr[0] && node.instr[1] && node.instr[2])
		if (prev_check(ft_strrchr(instr - 1, '\n') + 1, op, node))
			return ;
	new = f[op](node, *(node.a), *(node.b));
	if (new && !dup_state(*root, *new))
		insert_new(root, new);
}
