/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimal_rotation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 11:26:34 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/16 11:26:34 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "optimal_rotation.h"
#include <unistd.h>
#include <stdio.h>

void	a_rotate_x_to(int target, int pos, t_tack a, t_word *start)
{
	int i;

	while (pos < 0)
		pos += a.length;
	while (pos >= a.length)
		pos -= a.length;
	if (a.stack[pos] != target)
	{
		i = pos;
		while (i <= pos + a.length && a.stack[i % a.length] != target)
			i++;
		if (a.stack[i] != target)
			return ;
		if (i > a.length / 2)
			while (a.stack[pos] != target)
				do_thing_a("rra", start, &a, NULL);
		else
			while (a.stack[pos] != target)
				do_thing_a("ra.", start, &a, NULL);
	}
}

void	b_rotate_x_to(int target, int pos, t_tack b, t_word *start)
{
	int i;

	while (pos < 0)
		pos += b.length;
	while (pos >= b.length)
		pos -= b.length;
	if (b.stack[pos] != target)
	{
		i = 0;
		while (i < b.length && b.stack[i] != target)
			i++;
		if (b.stack[i] != target)
			return ;
		i = (i - pos + b.length) % b.length;
		if (i > b.length / 2)
			while (b.stack[pos] != target)
				do_thing_b("rrb", start, NULL, &b);
		else
			while (b.stack[pos] != target)
				do_thing_b("rb.", start, NULL, &b);
	}
}

int		find_biggest(int *stk, int len, int length)
{
	int i;
	int biggest;

	if (len <= 0)
		return (-1);
	biggest = stk[0];
	i = 1;
	while (i < len && i < length)
	{
		if (stk[i] > biggest)
			biggest = stk[i];
		i++;
	}
	return (biggest);
}

void	rotation_a(t_tack st, int i, t_word *list)
{
	int *stk;

	stk = st.stack;
	if (i > st.length / 2)
		i -= st.length;
	while (i > 0)
	{
		if (st.length > 2)
			swap_a_maybe(st, list);
		do_thing_a("ra.", list, &st, NULL);
		i--;
	}
	while (i < 0)
	{
		if (st.length > 2)
			swap_a_maybe(st, list);
		do_thing_a("rra", list, &st, NULL);
		i++;
	}
}

void	rotation_b(t_tack st, int i, t_word *list)
{
	int *stk;

	stk = st.stack;
	if (i > st.length / 2)
		i -= st.length;
	while (i > 0)
	{
		if (st.length > 2)
			swap_b_maybe(st, list);
		do_thing_b("rb.", list, NULL, &st);
		i--;
	}
	while (i < 0)
	{
		if (st.length > 2)
			swap_b_maybe(st, list);
		do_thing_b("rrb", list, NULL, &st);
		i++;
	}
}
