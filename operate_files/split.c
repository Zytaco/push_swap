/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:24:10 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/16 12:24:10 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"
#include <stdio.h>

/*
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
*/

/*
** Pushes the higher valued half within the width to b
** while rotating past the lower valued half.
** Then pushes everything back and then rotates everything back.
** Effectively everything within the width is split in half with everythin at
** or before half the width being smaller than everything after half the width.
*/

static void	push_swaps_a(t_tack *a, t_tack *b, int pivot, t_word *start)
{
	if (a->length >= 4 && a->stack[0] >= pivot && a->stack[1] >= pivot)
	{
		while (a->stack[0] >= pivot && a->stack[1] >= pivot)
		{
			do_thing_b("pb", start, a, b);
			do_thing_b("pb", start, a, b);
			swap_a_maybe(*a, start);
			swap_b_maybe(*b, start);
			if (a->stack[0] >= pivot && a->stack[1] >= pivot)
			{
				do_thing_b("pb", start, a, b);
				do_thing_b("pb", start, a, b);
			}
		}
	}
	swap_a_maybe(*a, start);
	swap_b_maybe(*b, start);
}

static void	push_swaps_b(t_tack *a, t_tack *b, int pivot, t_word *start)
{
	if (b->length >= 4 && b->stack[0] >= pivot && b->stack[1] >= pivot)
	{
		while (b->stack[0] >= pivot && b->stack[1] >= pivot)
		{
			do_thing_a("pa", start, a, b);
			do_thing_a("pa", start, a, b);
			swap_b_maybe(*b, start);
			swap_a_maybe(*a, start);
			if (b->stack[0] >= pivot && b->stack[1] >= pivot)
			{
				do_thing_a("pa", start, a, b);
				do_thing_a("pa", start, a, b);
			}
		}
	}
	swap_b_maybe(*b, start);
	swap_a_maybe(*a, start);
}

void		split_a(t_tack *a, t_tack *b, int width, t_word *start)
{
	int	i;
	int	*stack;
	int pivot;
	int a_len;

	stack = a->stack;
	a_len = a->length;
	if (width > a_len)
		width = a_len;
	pivot = find_lowest(stack, a_len) + (width / 2);
	if (pivot <= 3)
		pivot = 4;
	i = 0;
	if (ordered_a(a->stack + 4, a->length - 4))
		push_swaps_a(a, b, pivot, start);
	while (i < width && i < a_len && !ordered_a(a->stack, a->length))
	{
		if (stack[0] >= pivot)
			do_thing_b("pb", start, a, b);
		else
			do_thing_a("ra", start, a, b);
		push_swaps_a(a, b, pivot, start);
		i++;
	}
}

void		split_b(t_tack *a, t_tack *b, int width, t_word *start)
{
	int	i;
	int	*stack;
	int pivot;
	int b_len;

	stack = b->stack;
	b_len = b->length;
	if (width > b_len)
		width = b_len;
	pivot = find_lowest(stack, b_len) + (width / 2);
	i = 0;
	if (ordered_a(b->stack + 4, b->length - 4))
		push_swaps_b(a, b, pivot, start);
	while (i < width && i < b_len && !ordered_a(b->stack, b->length))
	{
		b_maybes(a, b, start);
		if (stack[0] < pivot)
			do_thing_a("pa", start, a, b);
		else
			do_thing_b("rb", start, a, b);
		push_swaps_b(a, b, pivot, start);
		i++;
	}
}
