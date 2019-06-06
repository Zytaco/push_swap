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

static int	needs_split(int width, int *stk, int len)
{
	int i;
	int biggest;

	biggest = find_lowest(stk, len) + (width / 2) - 1;
	i = 0;
	while (i < width)
	{
		if (stk[i] > biggest)
			return (1);
		i++;		
	}
	return (0);
}

int			ordered(int *stk, int len)
{
	int i;
	int lowest;

	lowest = find_lowest(stk, len);
	if (len <= 0)
		return (0);
	i = len - 1;
	if (len > 2 && stk[i] > stk[0] && stk[0] != lowest)
		return (0);
	while (i > 0)
	{
		i--;
		if (stk[i] > stk[i + 1] && !(stk[i + 1] == lowest))
			return(0);
	}
	return (1);
}

static void	lowest_to_front(t_tack a, t_word *start)
{
	int i;
	int lowest;
	int *stk;
	int len;

	stk = a.stack;
	len = a.length;
	lowest = find_lowest(stk, len);
	i = 0;
	while (i < len && stk[i] != lowest)
		i++;
	rotation(a, i, start, 'a');
}

/*
** width means how muc hsplit will go over while pa-ing and ra-ing
** The plan of solver is as follows:
** First rotate the already ordered part of A to the tail of A where it will be ignored untill the very end.
** Repeatedly push the four lowest values in A (ignoring the tail) to B and order them with swaps while doing so.
** to get the lowest and second lowest pairs to the front of A splits are repeatedly done on A when neccesary.
** Finally push everything back to A after rotating it correctly and then rotating A correctly again to get 0 in front.
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
		rotation(*a, i, start, 'a');
	do_thing_a("pa.", start, a, b);
}

static void	insert_all(t_tack *a, t_tack *b, t_word *start)
{
	swap_a_maybe(*a, start);
	swap_b_maybe(*b, start);
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
	int i;

	if (a->stack[0] != 0)
		return ;
	i = 0;
	while (i + 1 < a->length && a->stack[i] + 1 == a->stack[i + 1])
		i++;
	if (i >= a->length / 2)
		return ;
	while (find_lowest(a->stack, a->length) == a->stack[0] &&
	(b->length == 0 || a->stack[0] == b->stack[0] + 1))
		do_thing_b("pb.", start, a, b);
	swap_a_maybe(*a, start);
}

void		solver(t_tack a, t_tack b, t_word *start)
{
	int width;

	while (!ordered(a.stack, a.length))
	{
		push_start(&a, &b, start);
		width = 2;
		while (width < a.length && needs_split(width, a.stack, a.length))
			width *= 2;
		while (width > 2 && !ordered(a.stack, a.length) &&
		needs_split(width, a.stack, a.length))
		{
			width /= 2;
			split(&a, &b, width, start);
		}
	}
	insert_all(&a, &b, start);
//	printf("%d %d %d %d %d %d\n", a.stack[0], a.stack[1], a.stack[2], a.stack[3], a.stack[4], a.stack[5]);
}
