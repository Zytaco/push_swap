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
	while (i < width / 2)
	{
		if (stk[i] > biggest)
			return (1);
		i++;		
	}
	return (0);
}

int			ordered(t_tack a)
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

static void	zero_to_front(t_tack a, t_word *start)
{
	int i;
	i = 0;
	while (i < a.length && a.stack[i] != 0)
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

static void	insert_to(t_tack *a, t_tack *b, t_word *start, char name)
{
	int i;
	int *stk;
	int insert;
	int mod;

	stk = a->stack;
	insert = b->stack[0];
	mod = a->length;
	i = mod - 1;
	if (bigger_than_stack(insert, a->stack, a->length))
		zero_to_front(*a, start);
	else
	{
		if (name == 'a')
			while (stk[(i - 1) % mod] > insert || insert > stk[i % mod])
				i++;
		else if (name == 'b')
			while (stk[(i - 1) % mod] < insert || insert < stk[i % mod])
				i++;
		rotation(*a, i, start, 'a');
	}	
	if (name == 'a')
		do_thing_a("pa.", start, a, b);
	if (name == 'b')
		do_thing_b("pb.", start, a, b);
}

static void	insert_all(t_tack a, t_tack b, t_word *start)
{
	swap_a_maybe(a, start);
	swap_b_maybe(b, start);
	while (b.length > 0)
	{
		insert_to(&a, &b, start, 'a');
		swap_a_maybe(a, start);
		swap_b_maybe(b, start);
	}
	zero_to_front(a, start);
}

void		solver(t_tack a, t_tack b, t_word *start)
{
	int width;

	while (!ordered(a))
	{
		width = 2;
		while (width < a.length && needs_split(width, a.stack, a.length))
			width *= 2;
		while (width > 2)
		{
			width /= 2;
			split(&a, &b, width, start);
		}
	}
	insert_all(a, b, start);
}
