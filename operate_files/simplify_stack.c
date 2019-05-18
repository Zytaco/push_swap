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

static int	find_lowest(int *stk, int len)
{
	int i;
	int lowest;

	lowest = stk[0];
	i = 1;
	while (i < len)
	{
		if (stk[i] < lowest)
			lowest = stk[i];
		i++;
	}
	return (lowest);
}

void		simplify_stack(t_tack *a)
{
	int *new;
	int i;
	int j;
	int lowest;

	new = (int*)malloc(sizeof(int) * a->length);
	lowest = find_lowest(a->stack, a->length);
	i = 0;
	j = 0;
	while (j < a->length)
	{
		if (a->stack[i] == lowest + j)
		{
			new[i] = j;
			j++;
			i = -1;
		}
		i++;
		if (i == a->length)
			lowest++;
		if (i == a->length)
			i = 0;
	}
	free(a->stack);
	a->stack = new;
}
