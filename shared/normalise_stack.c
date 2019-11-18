/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalise_stack.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:05:03 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/14 18:05:03 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_min_pos(t_array a)
{
	int min_pos;
	int i;

	min_pos = 0;
	i = 1;
	while (i < a.len)
	{
		if (a.stack[i] > a.stack[min_pos])
			min_pos = i;
		i++;
	}
	return (min_pos);
}

int		get_max_pos(t_array a)
{
	int max_pos;
	int i;

	max_pos = 0;
	i = 1;
	while (i < a.len)
	{
		if (a.stack[i] > a.stack[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}

void	normalise_stack(t_array a)
{
	int *new_stack;
	int min;
	int min_pos;

	new_stack = malloc(sizeof(int) * a.len);
	new_stack[get_max_pos(a)] = a.len - 1;
	min = 0;
	while (min < a.len - 1)
	{
		min_pos = get_min_pos(a);
		new_stack[min_pos] = min;
		a.stack[min_pos] = INT32_MAX;
		min++;
	}
	free(a.stack);
	a.stack = new_stack;
}
