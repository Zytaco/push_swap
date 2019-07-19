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

void		printf_stacks(t_tack *a, t_tack *b)
{
	int i;

	if (a != NULL)
		printf("a: %d ", a->length);
	if (b != NULL)
		printf("b: %d ", b->length);
	printf("\n");
	if (a != NULL)
	{
		printf("a: ");
		i = 0;
		while (i < a->length)
			printf("%d ", a->stack[i++]);
		printf("\n");
	}
	if (b != NULL)
	{
		printf("b: ");
		i = 0;
		while (i < b->length)
			printf("%d ", b->stack[i++]);
		printf("\n");
	}
	printf("\n");
}

/*
** width means how much split will go over while pa-ing and ra-ing
** The plan of solver is as follows:
** First rotate the already ordered part of A to the tail of A
** where it will be ignored untill the very end.
**
** Repeatedly push the four lowest values in A (ignoring the tail) to B
** and order them with swaps while doing so.
** to get the lowest and second lowest pairs to the front of A,
** splits are repeatedly done on A when neccesary.
** Finally push everything back to A after rotating it correctly
** and then rotating A correctly again to get 0 in front.
*/

/*
** gets the smallest power of 2 that's at least as big as target.
*/

int			get_power_of_two(int target)
{
	int i;

	i = 1;
	while (i < target)
		i *= 2;
	return (i);
}

/*
** adjust x in tail + x for what's left unordered after splitting
*/

int			get_width_a(int length)
{
	int width;

	width = 2;
	while (width < length)
		width *= 2;
	while (width / 2 < BLOCK)
		width += 2;
	return (width);
}

/*
** adjust x in tail + x for what's left unordered after splitting
*/

/*
** finds the smallest power of 2 that's at least 8 and at most the length of b
** ignoring b's tail.
*/

/*
** pushes then splits everything to b. Except an ordered tail.
** And except the last three elements which are easily ordered.
** Should always leave a sorted, although probably mostly empty.
*/

/*
**   a: 5 6 7 8
**   b: 4 3 2 1 0
*/

/*
** first pushes ordered or orderable parts to a.
** Then splits half the biggest continuos part to a.
** This part has to contain all numbers between the biggest & smallest values.
** It also has to have have the length of a power of 2.
*/

void		sort_b(t_tack *a, t_tack *b, t_word *start)
{
	int width;

	while (b->length > 0 && b->stack[0] + 1 == b->stack[b->length - 1])
		do_thing_b("rb.", start, a ,b);
	b_rotate_x_to(a->length + b->length - 1, b->length - b->tail, *b, start);
	width = 2;
	while (width < b->length - b->tail && !(
	find_biggest(b->stack, width, b->length - b->tail) ==
	b->stack[b->length - 1] &&
	find_lowest(b->stack, width, b->length - b->tail) + width - 1
	== find_biggest(b->stack, width, b->length - b->tail)))
		width += 2;
	if (width / 2 > b->length - b->tail)
		width = (b->length - b->tail) * 2;
	split_b(a, b, width, start);
	b_rotate_x_to(a->length + b->length - 1, b->length - b->tail, *b, start);
}

void		solver(t_tack a, t_tack b, t_word *start)
{
	b.tail = 0;
	while (!(b.tail >= a.length + b.length ||
	(b.length == 0 && ordered_a(a.stack, a.length))))
	{
		sort_a(&a, &b, start);
		if (b.length > 0 && !ordered_b(b.stack, b.length))
			sort_b(&a, &b, start);
	}
	rotate_to_front(&a, start, find_lowest(a.stack, a.length, a.length), 'a');
	push_all(&a, &b, start);
	rotate_to_front(&a, start, find_lowest(a.stack, a.length, a.length), 'a');
}
