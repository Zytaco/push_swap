/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:50 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:51 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
** 1 2 3 4
** 2 3 4 1 
*/
t_stacks			rb(t_stacks stacks, char free)
{
	t_stacks new;

	new.b = rot(stacks.b);
	new.a = copy(stacks.a, 0);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
