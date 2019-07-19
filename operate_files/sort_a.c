/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_a.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 14:15:19 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/07/04 14:15:19 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sort_a.h"

void		short_sorts(t_tack *a, t_tack *b, t_word *start)
{
	if (ordered_a(a->stack, a->length))
		a_rotate_x_to(find_lowest(a->stack, a->length, 3), 0, *a, start);
	if (a->length <= 1)
		return ;
	while (a->length > 3)
		do_thing_b("pb.", start, a, b);
	swap_a_maybe(*a, start);
	swap_b_maybe(*b, start);
	if (a->length <= 3 && (a->stack[0] > a->stack[1] ||
	a->length <= 2 || a->stack[0] > a->stack[2]))
	{
		a_rotate_x_to(find_lowest(a->stack, a->length, 0), 0, *a, start);
		return ;
	}
}

int			additional_a_pushes(t_tack *a, t_tack *b, t_word *start)
{
	int len;
	int copy;

	len = BLOCK;
	if (b->length < BLOCK)
		len = b->length;
	while (len > 0 && !(find_biggest(b->stack, len, b->length - b->tail) ==
	b->stack[b->length - 1] - 1 &&
	find_lowest(b->stack, len, b->length - b->tail) + len - 1 ==
	find_biggest(b->stack, len, b->length - b->tail)))
		len--;
	if (len == 0)
		return (0);
	copy = len;
	while (len > 0)
	{
		do_thing_a("pa.", start, a, b);
		len--;
	}
	return (1);
}

void		sort_a(t_tack *a, t_tack *b, t_word *start)
{
	int tail_init;

	tail_init = b->tail;
	while (a->length > BLOCK)
	{
		split_a(a, b, get_width_a(a->length), start);
		if (b->tail != tail_init)
		{
			b_rotate_x_to(a->length + b->length - 1, b->length - b->tail,
			*b, start);
			tail_init = b->tail;
		}
	}
	if (a->length > 0 &&
	find_biggest(a->stack, a->length, BLOCK) + 1 != a->length + b->length &&
	find_biggest(a->stack, a->length, BLOCK) + 1 != b->stack[b->length - 1])
	{
		while (a->length > 0)
			do_thing_b("pb.", start, a, b);
		return ;
	}
	insertion_push_a(a, b, start);
	while (additional_a_pushes(a, b, start))
		insertion_push_a(a, b, start);
}
