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
static int bigger_than_stack(int bigger, int *stk, int len)
{
	int i;

	i = 0;
	while (i < len && bigger > stk[i])
		i++;
	if (i == len)
		return (1);
	else
		return (0);
}
*/

static void	insert_to_a(t_tack *a, t_tack *b, int insert, t_word *start)
{
	int i;
	int *stk;

	stk = a->stack;
	if (stk[a->length - 1] < insert && insert < stk[0])
	{
		do_thing_a("pa.", start, a, b);
		return ;
	}
	i = a->length - 1;
	while (i >= 1 && (stk[i - 1] > insert || insert > stk[i]))
		i--;
	if (i == 0)
		lowest_to_front(*a, start);
	else
		rotation_a(*a, i, start);
	do_thing_a("pa.", start, a, b);
}

static void	insert_all(t_tack *a, t_tack *b, t_word *start)
{
	while (b->length > 0)
	{
		insert_to_a(a, b, b->stack[0], start);
		swap_a_maybe(*a, start);
		swap_b_maybe(*b, start);
	}
	lowest_to_front(*a, start);
}

static void	push_start(t_tack *a, t_tack *b, t_word *start)
{
	while (a->length >= 2 && (a->stack[0] == b->length ||
	a->stack[1] == b->length))
	{
		if (a->stack[0] == b->length + 1 && a->stack[1] == b->length)
		{
			do_thing_b("pb.", start, a, b);
			do_thing_b("pb.", start, a, b);
			swap_a_maybe(*a, start);
			swap_b_maybe(*b, start);
		}
		else
		{
			swap_a_maybe(*a, start);
			if (a->stack[0] == 0)
			{
				do_thing_b("pb.", start, a, b);
				swap_a_maybe(*a, start);
			}
		}
	}
}

void		solver(t_tack a, t_tack b, t_word *start)
{
	int width;

	push_start(&a, &b, start);
	while (!ordered(a.stack, a.length))
	{
		width = 4;
		while (width < a.length && needs_split_a(width, a.stack, a.length))
			width *= 2;
		while (width > 4 && !ordered(a.stack, a.length) &&
		needs_split_a(width, a.stack, a.length))
		{
			width /= 2;
			split_a(&a, &b, width, start);
		}
	}
	insert_all(&a, &b, start);
}
