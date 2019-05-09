/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simplify_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 17:05:36 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/09 17:05:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "simplify_stack.h"

static int	find_lowest(t_tack a)
{
	int i;
	int lowest;

	lowest = a.stack[0];
	i = 0;
	while (i < a.length)
	{
		if (a.stack[i] < lowest)
			lowest = a.stack[i];
		i++;
	}
	return (lowest);
}

void		simplify_stack(t_tack a)
{
	int *new;
	int i;
	int j;
	int lowest;

	new = (int*)malloc(sizeof(int) * a.length);
	lowest = find_lowest(a);
	i = 0;
	j = 0;
	while (j < a.length)
	{
		if (a.stack[i] == lowest + j)
		{
			new[i] = lowest + j;
			j++;
			i = 0;
		}
		i++;
		if (i == a.length)
			lowest++;
		if (i == a.length)
			i = 0;
	}
	free(a.stack);
	a.stack = new;
}
