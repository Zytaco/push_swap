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
