/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rr.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:54 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:55 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stacks			rr(t_stacks stacks, char free)
{
	t_stacks new;

	new.a = rot(stacks.a);
	new.b = rot(stacks.b);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
