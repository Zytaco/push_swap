/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ss.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:31 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:31 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stacks			ss(t_stacks stacks, char free)
{
	t_stacks new;

	new.a = swap(stacks.a);
	new.b = swap(stacks.b);
	if (free)
	{
		ft_free(stacks.a.stack);
		ft_free(stacks.b.stack);
	}
	return (new);
}
