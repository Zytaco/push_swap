/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrr.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:05:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:05:07 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stacks			rrr(t_stacks stacks, char free)
{
	t_stacks new;

	new.a = rev_rot(stacks.a);
	new.b = rev_rot(stacks.b);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
