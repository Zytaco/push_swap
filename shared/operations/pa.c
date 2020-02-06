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

t_stacks			pa(t_stacks stacks, char free)
{
	t_stacks new;

	if (stacks.b.size <= 0)
		return (id(stacks, free));
	new.a = copy(stacks.a, 1);
	stacks.a.stack[0] = stacks.b.stack[0];
	new.b = copy(stacks.b, -1);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
