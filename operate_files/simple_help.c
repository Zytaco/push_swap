/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_help.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 13:25:11 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/09 13:25:11 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "simple_help.h"
#include <unistd.h>
#include <stdio.h>

int		find_lowest(int *stk, int len, int length)
{
	int lowest;
	int i;

	lowest = stk[0];
	i = 1;
	while (i < len && i < length)
	{
		if (stk[i] < lowest)
			lowest = stk[i];
		i++;
	}
	return (lowest);
}

void	lowest_to_front(t_tack a, t_word *start)
{
	int i;
	int lowest;
	int *stk;
	int len;

	stk = a.stack;
	len = a.length;
	lowest = find_lowest(stk, len, len);
	i = 0;
	while (i < len && stk[i] != lowest)
		i++;
	rotation_a(a, i, start);
}

/*
** 1 only if every element in a is bigger than the last
** unless it's the smallest element.
*/

int		ordered_a(int *stk, int len)
{
	int i;
	int lowest;

	lowest = find_lowest(stk, len, len);
	if (len <= 1)
		return (1);
	i = len - 1;
	if (len > 2 && stk[i] > stk[0] && stk[0] != lowest)
		return (0);
	while (i > 0)
	{
		i--;
		if (stk[i] >= stk[i + 1] && !(stk[i + 1] == lowest))
			return (0);
	}
	return (1);
}

/*
** 1 only if every element in a is smaller than the last
** unless it's the biggest element.
*/

int		ordered_b(int *stk, int len)
{
	int i;
	int biggest;

	biggest = find_biggest(stk, len, len);
	if (len <= 0)
		return (1);
	i = len - 1;
	if (len > 2 && stk[i] < stk[0] && stk[0] != biggest)
		return (0);
	while (i > 0)
	{
		i--;
		if (stk[i] <= stk[i + 1] && !(stk[i + 1] == biggest))
			return (0);
	}
	return (1);
}
