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

#include "../../includes/push_swap.h"

void		op_dispatch(t_ops op, t_node node, t_node **root, char *instr)
{
	t_node	*(*const f[11])(t_node) = {alt_sa, alt_sb, alt_ss, alt_pa,
					alt_pb, alt_ra, alt_rb, alt_rr, alt_rra, alt_rrb, alt_rrr};
	int		len;

	len = ft_strlen(node.instr);
	if ((node.a->len <= 1 && (op == 0 || op == 2 || op == 5 || op == 7 ||
	op == 8 || op == 10)) || (node.b->len <= 1 && (op == 1 || op == 2 ||
	op == 6 || op == 7 || op == 9 || op == 10)) ||
	(node.a->len <= 0 && op == 4) || (node.b->len <= 0 && op == 3)
	|| (ft_strequ(&instr[len - 4], "\nsa\n") && op_sa == op)
	|| (ft_strequ(&instr[len - 4], "\nsb\n") && op_sb == op)
	|| (ft_strequ(&instr[len - 4], "\nss\n") && (op_sa <= op && op <= op_ss))
	|| (ft_strequ(&instr[len - 4], "\npa\n") && op_pb == op)
	|| (ft_strequ(&instr[len - 4], "\npb\n") && op_pa == op)
	|| (ft_strequ(&instr[len - 4], "\nra\n") && op_rra == op)
	|| (ft_strequ(&instr[len - 4], "\nrb\n") && op_rrb == op)
	|| (ft_strequ(&instr[len - 4], "\nrr\n") && (op_rra <= op && op <= op_rrr))
	|| (ft_strequ(&instr[len - 5], "\nrra\n") && op_ra == op)
	|| (ft_strequ(&instr[len - 5], "\nrrb\n") && op_rb == op)
	|| (ft_strequ(&instr[len - 5], "\nrrr\n") && (op_ra <= op && op <= op_rr)))
		return ;
	insert_new(root, f[op](node));
}
