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
		do_thing_a("pa.", start, a, b);
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

void		push_four(t_tack *a, t_tack *b, t_word *start)
{
	do_thing_b("pb.", start, a, b);
	do_thing_b("pb.", start, a, b);
	if (b->length >= 2 && b->stack[1] > b->stack[0])
		do_thing_b("sb.", start, a, b);
	if (a->length >= 2 && a->stack[0] > a->stack[1])
		do_thing_a("sa.", start, a, b);
	do_thing_b("pb.", start, a, b);
	do_thing_b("pb.", start, a, b);
}

void		push_remainder(t_tack *a, t_tack *b, t_word *start)
{
	swap_a_maybe(*a, start);
	do_thing_b("pb.", start, a, b);
	if (a->length >= 2 && a->stack[0] + 1 == a->stack[1])
		do_thing_a("sa.", start, a, b);
	while (a->length > 0)
		do_thing_b("pb.", start, a, b);
}
