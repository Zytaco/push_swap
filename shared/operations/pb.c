/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:42 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:42 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stacks			pb(t_stacks stacks, char free)
{
	t_stacks new;

	if (stacks.a.size <= 0)
		return (id(stacks, free));
	new.b = copy(stacks.b, 1);
	new.b.stack[0] = stacks.a.stack[0];
	new.a = copy(stacks.a, -1);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
