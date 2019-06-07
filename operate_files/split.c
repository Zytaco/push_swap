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

void		do_thing_a(char *s, t_word *start, t_tack *a, t_tack *b)
{
	if (s[0] == 'r' && s[1] == 'a')
	{
		new_to_list(start, "ra.");
		rotate(a->stack, a->length);
	}
	else if (s[0] == 'p' && s[1] == 'a')
	{
		new_to_list(start, "pa.");
		push(a, b);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
	{
		new_to_list(start, "rra");
		reverse_rotate(a->stack, a->length);
	}
	else if (s[0] == 's' && s[1] == 'a')
	{
		new_to_list(start, "sa.");
		swap(*a);
	}
}

void		do_thing_b(char *s, t_word *start, t_tack *a, t_tack *b)
{
	if (s[0] == 'r' && s[1] == 'b')
	{
		new_to_list(start, "rb.");
		rotate(b->stack, b->length);
	}
	else if (s[0] == 'p' && s[1] == 'b')
	{
		new_to_list(start, "pb.");
		push(b, a);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b')
	{
		new_to_list(start, "rrb");
		reverse_rotate(b->stack, b->length);
	}
	else if (s[0] == 's' && s[1] == 'b')
	{
		new_to_list(start, "sb.");
		swap(*b);
	}
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

/*
** Pushes the higher valued half within the width to b
** while rotating past the lower valued half.
** Then pushes everything back and then rotates everything back.
** Effectively everything within the width is split in half with everythin at
** or before half the width being smaller than everything after half the width.
*/

static int	push_ss(t_tack *a, t_tack *b, int pivot, t_word *start)
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
		return (1);
	}
	return (0);
}

void		split(t_tack *a, t_tack *b, int width, t_word *start)
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
	i = 0;
	if (ordered(a->stack + 4, a->length - 4))
	{
		push_ss(a, b, pivot, start);
		swap_a_maybe(*a, start);
		swap_b_maybe(*b, start);
	}
	while (i < width && i < a_len && !ordered(a->stack, a->length))
	{
		if (stack[0] >= pivot && a->length > 3)
			do_thing_b("pb", start, a, b);
		else
			do_thing_a("ra", start, a, b);
		push_ss(a, b, pivot, start);
		swap_a_maybe(*a, start);
		swap_b_maybe(*b, start);
		i++;
	}
}
