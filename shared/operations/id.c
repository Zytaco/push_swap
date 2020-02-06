/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   id.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 12:46:46 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/06 12:46:46 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stacks			id(t_stacks stacks, char free)
{
	t_stacks new;

	new.a = copy(stacks.a, 0);
	new.b = copy(stacks.b, 0);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
