/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   b_tools.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:55:32 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/09 12:55:32 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "b_tools.h"
#include <stdio.h>

void	do_thing_b(char *s, t_word *start, t_tack *a, t_tack *b)
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

int		swap_b_maybe(t_tack b, t_word *start)
{
	int l;
	int *stk;
	int low;
	int big;

	l = b.length;
	stk = b.stack;
	low = find_lowest(stk, l, l);
	big = find_biggest(stk, l, l);
	if (l < 2 || (l > 2 &&
	(stk[0] - 1 == stk[1] || stk[1] - 1 == stk[2] || stk[l - 1] - 1 == stk[0]
	|| (stk[0] == low && stk[1] == big) || (stk[1] == low && stk[2] == big) ||
	(stk[l - 1] == low && stk[0] == big))))
		return (0);
	if ((l == 2 && stk[0] < stk[1]) || (l > 2 &&
	(stk[0] + 1 == stk[1] || stk[1] + 1 == stk[2] || stk[l - 1] + 1 == stk[0]
	|| (stk[0] == big && stk[1] == low) || (stk[1] == big && stk[2] == low) ||
	(stk[l - 1] == big && stk[0] == low))))
	{
		do_thing_b("sb.", start, NULL, &b);
		return (1);
	}
	return (0);
}

int		rotate_b_maybe(t_tack b, t_word *list, int biggest)
{
	int i;
	int *stk;
	int start;

	if (b.length <= 1)
		return (0);
	stk = b.stack;
	i = 0;
	while (stk[i] != biggest && i < b.length)
		i++;
	start = i;
	while (stk[i % b.length] - 1 == stk[(i + 1) % b.length])
		i++;
	if ((i % (b.length / 2)) > ((i - start) % b.length))
	{
		rotation_b(b, i, list);
		return (1);
	}
	swap_b_maybe(b, list);
	return (0);
}

int		x_less(int x, int minus, t_tack a, t_tack b)
{
	return ((x + a.length + b.length - minus) % (a.length + b.length));
}

int		push_b_maybe(t_tack *a, t_tack *b, t_word *start)
{
	int ret;

	ret = 0;
	if ((b->length >= 1 && b->stack[0] == x_less(a->stack[0], 1, *a, *b)) ||
	(b->length >= 2 && (b->stack[0] == x_less(a->stack[0], 2, *a, *b) &&
	b->stack[1] == x_less(a->stack[0], 1, *a, *b))))
		ret = 1;
	while ((b->length >= 1 && b->stack[0] == x_less(a->stack[0], 1, *a, *b)) ||
	(b->length >= 2 && (b->stack[0] == x_less(a->stack[0], 2, *a, *b) &&
	b->stack[1] == x_less(a->stack[0], 1, *a, *b))))
	{
		if (b->stack[0] == x_less(a->stack[0], 1, *a, *b))
			do_thing_a("pa.", start, a, b);
		else
		{
			do_thing_a("pa.", start, a, b);
			do_thing_a("pa.", start, a, b);
			swap_b_maybe(*b, start);
			swap_a_maybe(*a, start);
		}
	}
	return (ret);
}
