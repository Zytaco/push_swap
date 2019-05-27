/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 09:57:03 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/15 09:57:03 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include <unistd.h>
#include <stdio.h>

int			find_lowest(int *stk, int len)
{
	int lowest;
	int i;

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

static int	tailles(int *stk, int len)
{
	int i;
	int j;

	i = 0;
	while (i < len && stk[i] != 0)
		i++;
	j = 0;
	while (i + j + 1 < len && stk[i + j] + 1 == stk[i + j + 1])
		j++;
	if (i + j + 1 >= len)
		return (i);
	else
		return (len);
}

static int	needs_split(int width, int *stk, int len)
{
	int i;
	int biggest;

	biggest = find_lowest(stk, tailles(stk, len)) + (width / 2) - 1;
	i = 0;
	while (i < width / 2)
	{
		if (stk[i] > biggest)
			return (1);
		i++;		
	}
	return (0);
}

static int	ordered(t_tack a)
{
	int *stk;
	int i;

	i = a.length - 1;
	stk = a.stack;
	if (stk[i] > stk[0] && stk[0] != 0)
		return (0);
	while (i > 0)
	{
		i--;
		if (stk[i] > stk[i + 1] && !(stk[i + 1] == 0))
			return(0);
	}
	return (1);
}

/*
** width means how muc hsplit will go over while pa-ing and ra-ing
** The plan of solver is as follows:
** First rotate the already ordered part of A to the tail of A where it will be ignored untill the very end.
** Repeatedly push the four lowest values in A (ignoring the tail) to B and order them with swaps while doing so.
** to get the lowest and second lowest pairs to the front of A splits are repeatedly done on A when neccesary.
** Finally push everything back to A after rotating it correctly and then rotating A correctly again to get 0 in front.
*/

int			swap_maybe(t_tack stack)
{
	int len;
	int *stk;

	len = stack.length;
	stk = stack.stack;
	if (len >= 2 &&
	((stk[0] - 1 == stk[1] && stk[len - 1] + 1 != stk[0]) ||
	(stk[len - 1] - 1 == stk[0] && stk[0] + 1 != stk[1])))
	{
		swap(stack);
		return (1);
	}
	return (0);
}

void		solver(t_tack a, t_tack b, t_word *start)
{
	int	width;

	while (!ordered(a))
	{
		width = 4;
		while (width < tailles(a.stack, a.length) * 2 &&
		needs_split(width, a.stack, tailles(a.stack, a.length)))
			width *= 2;
		while (width > 4)
		{
			width /= 2;
			if (width < tailles(a.stack, a.length) * 2 && width >= 4)
				split(&a, &b, width, start);
			optimal_rotation(a, start);
		}
		if (tailles(a.stack, a.length) >= 4)
			push_four(&a, &b, start);
		else
			push_remainder(&a, &b, start);
		optimal_rotation(a, start);
	}
	if (b.length > 0)
	{
		optimal_rotation(a, start);
		push_all(&a, &b, start);
	}
	rotate_to_front(&a, start);
}
