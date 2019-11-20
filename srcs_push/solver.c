/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 17:52:17 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/14 17:52:17 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ordered(t_array a, char stack)
{
	int i;

	if (!a.stack || a.len <= 0 || (stack != 'a' && stack != 'b'))
		return (-1);
	i = 0;
	while (i + 1 < a.len)
	{
		if (stack == 'a')
			if (a.stack[i] + 1 != a.stack[i + 1])
				return (0);
		if (stack == 'b')
			if (a.stack[i] - 1 != a.stack[i + 1])
				return (0);
		i++;
	}
	return (1);
}

int		is_ordered(t_array a, char stack)
{
	int i;

	i = 0;
	while (i + 1 < a.len)
	{
		if (stack == 'a' && a.stack[i] >= a.stack[i + 1])
			return (0);
		if (stack == 'b' && a.stack[i] <= a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	solver(t_data data)
{
	t_array *longest_subseq;

	longest_subseq = find_longest_subseq(data.a, 'a');
}
