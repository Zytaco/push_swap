/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/26 10:21:54 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/26 10:21:54 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		push_all(t_tack *a, t_tack *b, t_word *start)
{
	int i;

	i = b->length;
	while (i > 0)
	{
		new_to_list(start, "pa.");
		push(a, b);
		i--;
	}
}

void		rotate_to_front(t_tack *a, t_word *start)
{
	int i;

	i = 0;
	while (a->stack[i] != 0)
		i++;
	rotation(*a, i, start, 'a');
}

static void push_push_helper(t_tack *a, t_tack *b, t_word *start)
{
	new_to_list(start, "pb.");
	push(b, a);
	new_to_list(start, "pb.");
	push(b, a);
	while (b->length > 0)
	{
		new_to_list(start, "pa.");
		push(a, b);
	}
}

void		push_four(t_tack *a, t_tack *b, t_word *start)
{
    push_push_helper(a, b, start);
	if (b->stack[1] > b->stack[0] && a->stack[0] > a->stack[1])
	{
		new_to_list(start, "ss.");
		swap(*a);
		swap(*b);
	}
	else
	{
		if (b->length >= 2 && b->stack[1] > b->stack[0])
		{
			new_to_list(start, "sb.");
			swap(*b);
		}
		else if (a->length >= 2 && a->stack[0] > a->stack[1])
		{
			new_to_list(start, "sa.");
			swap(*a);
		}
	}
    push_push_helper(a, b, start);
}

void		push_remainder(t_tack *a, t_tack *b, t_word *start)
{
	if (a->length >= 2 && a->stack[0] + 1 == a->stack[1])
	{
		swap(*a);
		new_to_list(start, "sa.");
	}
	push(b, a);
	new_to_list(start, "pb.");
	if (a->length >= 2 && a->stack[0] + 1 == a->stack[1])
	{
		swap(*a);
		new_to_list(start, "sa.");
	}
	while (a->length > 0)
	{
		push(b, a);
		new_to_list(start, "pb.");
	}
}
