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

t_stacks	op_dispatch(t_ops op, t_stacks stacks, char free)
{
	t_stacks	(*const f[])(t_stacks, char) = {
	id, sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

	return (f[op](stacks, free));
}
