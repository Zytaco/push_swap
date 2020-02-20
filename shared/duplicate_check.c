/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   duplicate_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 12:04:34 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/14 12:04:35 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		duplicate_check(t_stacks stacks)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < stacks.a.size + stacks.b.size)
	{
		j = i + 1;
		while (j < stacks.a.size + stacks.b.size)
		{
			if ((i < stacks.a.size ?
			stacks.a.stack[i] : stacks.b.stack[i - stacks.a.size]) ==
			(j < stacks.a.size ?
			stacks.a.stack[j] : stacks.b.stack[j - stacks.a.size]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
