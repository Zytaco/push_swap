/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:28 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:28 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stacks			sb(t_stacks stacks, char free)
{
	t_stacks new;

	new.a = copy(stacks.a, 0);
	new.b = swap(stacks.b);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
