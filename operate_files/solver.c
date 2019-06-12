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
*/

static void	push_start(t_tack *a, t_tack *b, t_word *start)
{
	if (a->stack[1] == b->length)
		swap_a_maybe(*a, start);
	while (a->length > 3 && (a->stack[0] == b->length ||
	(a->stack[0] == b->length + 1 && a->stack[1] == b->length)))
	{
		if (a->stack[0] == b->length)
			do_thing_b("pb.", start, a, b);
		else
		{
			do_thing_b("pb.", start, a, b);
			do_thing_b("pb.", start, a, b);
			swap_b_maybe(*b, start);
			swap_a_maybe(*a, start);
		}
	}
	swap_b_maybe(*b, start);
	swap_a_maybe(*a, start);
}

int			next_four(int seed, int *stk, int offset)
{
	if (stk[0 + offset] >= seed || stk[0 + offset] < seed - 4 ||
	stk[1 + offset] >= seed || stk[1 + offset] < seed - 4 ||
	stk[2 + offset] >= seed || stk[2 + offset] < seed - 4 ||
	stk[3 + offset] >= seed || stk[3 + offset] < seed - 4)
		return (0);
	return (1);
}

int			get_power_of_two(int target)
{
	int i;

	i = 1;
	while (i < target)
		i *= 2;
	return (i);
}

/*
** makes a sorted mostly by splitting things to stack b
*/

void		sort_a(t_tack *a, t_tack *b, t_word *start)
{
	int width;
	int tail;

	if (a->length <= 4)
	{
		shuffle_sort_a(a->length, a, b, start);
		return ;
	}
	tail = tail_a(a->stack, a->length);
	width = get_power_of_two(a->length - tail);
	while (a->length - tail > 4)
	{
		split_a(a, b, width, start);
		tail = tail_a(a->stack, a->length);
		get_power_of_two(a->length - tail);
	}
	shuffle_sort_a(a->length - tail, a, b, start);
}

int			check_range(int *stk, int seed, int range)
{
	int i;
	int j;

	i = 0;
	while (i < range)
	{
		j = 0;
		while (j < range && stk[j] != seed - i)
			j++;
		if (j == range)
			return (0);
		i++;
	}
	return (1);
}

int			find_width_b(t_tack b)
{
	int width;
	int tail;

	tail = tail_b(b.stack, b.length);
	width = 8;
	while (width <= b.length &&
	check_range(b.stack, b.length, width))
		width *= 2;
	return (width);
}

void		solver(t_tack a, t_tack b, t_word *start)
{
	push_start(&a, &b, start);
	while (!ordered_a(a.stack, a.length) || !ordered_b(b.stack, b.length))
	{
		sort_a(&a, &b, start);
		while ((b.length >= 1 && b.stack[0] == a.length) ||
		(b.length >= 4 && next_four(a.length, b.stack, 0)))
		{
			if (b.length >= 1 && b.stack[0] == a.length)
				do_thing_a("pa.", start, &a, &b);
			else
			{
				push_four(&a, &b, start);
				shuffle_sort_a(4, &a, &b, start);
			}
		}
		split_b(&a, &b, find_width_b(b), start);
	}
	rotate_to_front(&a, start);
	push_all(&a, &b, start);
}

/*
** 2:
** 1: AAAAAAAAAAAAAAAA
**
** 2: AAAAAAAA
** 1: BBBBBBBB
**
** 2: BBBBAAAAAAAA
** 1: CCCC
**
** 2: CCBBBBAAAAAAAA
** 1: DD
**
** 2: EDCCBBBBAAAAAAAA
** 1:
**
** 2: FEDDCCCCBBBB
** 1: AAAA
**
** 2: GFEEDDDDCC
** 1: BBAAAA
**
** 2: GFEEDDDDCC
** 1: BBAAAA
**
** 2:
** 1:
**
**
**
**
** 2:
** 1: AAAAAAAA
**
** 2: AAAA
** 1: BBBB
**
** 2: BBAAAA
** 1: CC
**
** 2: CBBAAAA
** 1: D
**
** 2: DCBBAAAA
** 1:
**
** 2: BBAAAA
** 1: CD
**
** 2: BAAAA
** 1: CDE
**
** 2: AAAA
** 1: BCDE
**
** 2: AA
** 1: BBCDEF
**
** 2: BAA
** 1: CDEFG
**
** 2: AA
** 1: BCDEDFG
**
** 2: A
** 1: BCDEFGH
**
** 2:
** 1: ABCDEFGH
**
**
**
** 2:
** 1: AAAAAAAAAAAA
**
** 2: AAAA
** 1: BBBBBBBB
**
** 2: BBBBAAAA
** 1: CCCC
**
** 2: CCBBBBAAAA
** 1: DD
**
** 2: DCBBBBAAAA
** 1: E
**
** 2: CBBBBAAAA
** 1: DE
**
** 2: BBBBAAAA
** 1: CDE
**
** 2: BBAAAA
** 1: CCDEF
**
** 2:CBBAAAA
** 1:DEFG
**
** 2:BBAAAA
** 1:CDEFG
**
** 2:
**
*/
