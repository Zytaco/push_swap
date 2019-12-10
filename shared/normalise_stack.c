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

int		get_min_pos(int *st, int len)
{
	int min_pos;
	int i;

	min_pos = 0;
	i = 1;
	while (i < len)
	{
		if (st[i] < st[min_pos])
			min_pos = i;
		i++;
	}
	return (min_pos);
}

int		get_max_pos(int *st, int len)
{
	int max_pos;
	int i;

	max_pos = 0;
	i = 1;
	while (i < len)
	{
		if (st[i] > st[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}

void	normalisestck(t_array a)
{
	int *newstck;
	int min;
	int min_pos;

	newstck = malloc(sizeof(int) * a.len);
	newstck[get_max_pos(a.stack, a.len)] = a.len - 1;
	min = 0;
	while (min < a.len - 1)
	{
		min_pos = get_min_pos(a.stack, a.len);
		newstck[min_pos] = min;
		a.stack[min_pos] = INT32_MAX;
		min++;
	}
	min = 0;
	while (min < a.len)
	{
		a.stack[min] = newstck[min];
		min++;
	}
	free(newstck);
}
