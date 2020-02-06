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

t_stacks			rrb(t_stacks stacks, char free)
{
	t_stacks new;

	new.a = copy(stacks.a, 0);
	new.b = rev_rot(stacks.b);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
