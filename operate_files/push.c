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
#include <stdio.h>

void		push_all(t_tack *a, t_tack *b, t_word *start)
{
	int i;

	i = b->length;
	while (i > 0)
	{
		do_thing_a("pa.", start, a, b);
		i--;
	}
}

void		rotate_to_front(t_tack *stk, t_word *start, int target, char stack)
{
	int i;

	i = 0;
	while (i < stk->length && stk->stack[i] != target)
		i++;
	if (stack == 'a')
		rotation_a(*stk, i, start);
	if (stack == 'b')
		rotation_b(*stk, i, start);
}

int			ordered_seq_a(int *stack, int len)
{
	int i;
	int jump;

	jump = 0;
	i = 0;
	while (i + 1 < len)
	{
		if (stack[i] + 1 != stack[i + 1])
		{
			if (jump == 0 && stack[i + 1] - stack[i] == len - 1)
				jump = 1;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void		insertion_push_a(t_tack *a, t_tack *b, t_word *start)
{
	int init;

	init = a->length;
	while (a->length > 0 && !(ordered_seq_a(a->stack, a->length)))
	{
		a_rotate_x_to(find_lowest(a->stack, a->length, BLOCK), 0, *a, start);
		do_thing_b("pb.", start, a, b);
		b->tail++;
	}
	while (a->length > 0)
	{
		do_thing_b("pb.", start, a, b);
		b->tail++;
	}
	b_rotate_x_to(a->length + b->length - 1, b->length - b->tail, *b, start);
}
