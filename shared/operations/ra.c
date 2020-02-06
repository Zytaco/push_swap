/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:47 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:47 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stacks			ra(t_stacks stacks, char free)
{
	t_stacks new;

	new.a = rot(stacks.a);
	new.b = copy(stacks.b, 0);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
