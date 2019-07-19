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
** Pushes the higher valued half within the width to b
** while rotating past the lower valued half.
** Then pushes everything back and then rotates everything back.
** Effectively everything within the width is split in half with everythin at
** or before half the width being smaller than everything after half the width.
*/

static void	push_swaps_a(t_tack *a, t_tack *b, int pivot, t_word *start)
{
	if (a->length >= 4 && a->stack[0] <= pivot && a->stack[1] <= pivot)
	{
		while (a->length >= 2 &&
		a->stack[0] <= pivot && a->stack[1] <= pivot)
		{
			do_thing_b("pb", start, a, b);
			do_thing_b("pb", start, a, b);
			swap_a_maybe(*a, start);
			swap_b_maybe(*b, start);
			if (a->stack[0] <= pivot && a->stack[1] <= pivot)
			{
				do_thing_b("pb", start, a, b);
				do_thing_b("pb", start, a, b);
			}
		}
		swap_a_maybe(*a, start);
		swap_b_maybe(*b, start);
	}
}

void		split_a(t_tack *a, t_tack *b, int width, t_word *start)
{
	int	i;
	int	*stack;
	int pivot;
	int a_len;

	stack = a->stack;
	a_len = a->length;
	pivot = find_biggest(stack, width, a_len) - (width / 2);
	if (ordered_a(a->stack + 4, a->length - 4))
		push_swaps_a(a, b, pivot, start);
	i = 0;
	while (a->length > a_len - width / 2 && a->length > width / 2)
	{
		swap_a_maybe(*a, start);
		if (stack[0] <= pivot)
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
	pivot = find_lowest(stack, width, b_len) + (width / 2);
	i = 0;
	while (b->length > b_len - width / 2 && b->length > width / 2 &&
	b->length > b->tail)
	{
		if (stack[0] == a->length + b->length - 1)
			return ;
		if (stack[0] >= pivot)
			do_thing_a("pa", start, a, b);
		else
			do_thing_b("rb", start, a, b);
		i++;
	}
}
