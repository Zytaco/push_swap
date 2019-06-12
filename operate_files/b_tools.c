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
	low = find_lowest(stk, l);
	big = find_biggest(stk, l);
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

/*
** shuffle sort is best when there's a tail and the stack <= 4
*/

/*
void	shuffle_sort_b(int len, t_tack *a, t_tack *b, t_word *start)
{
	int init;

	if (len >= 2)
		shuffle_swap(*a, 'b', start);
	init = len;
	while (len >= 3)
	{
		do_thing_b("rb.", start, a, b);
		len--;
		shuffle_swap(*a, 'b', start);
	}
	while (len < init)
	{
		do_thing_b("rrb", start, a, b);
		len++;
		shuffle_swap(*a, 'b', start);
	}
}
*/

int		needs_split_b(int width, int *stk, int len)
{
	int i;
	int biggest;

	biggest = find_lowest(stk, len) + (width / 2) - 1;
	i = 0;
	while (i < width)
	{
		if (stk[i] <= biggest)
			return (1);
		i++;
	}
	return (0);
}

/*
** b_maybes comes with integrated push_biggest.
*/

int		push_b_maybe(t_tack *a, t_tack *b, t_word *start)
{
	int ret;

	ret = 0;
	if (b->stack[0] == b->length - 1 || (b->stack[0] == b->length - 2 &&
	b->stack[1] == b->length - 1))
		ret = 1;
	while (b->stack[0] == b->length - 1 || (b->stack[0] == b->length - 2 &&
	b->stack[1] == b->length - 1))
	{
		if (b->stack[0] == b->length - 1)
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

int		b_maybes(t_tack *a, t_tack *b, t_word *start)
{
	int ret;

	ret = 0;
	while (push_b_maybe(a, b, start) || swap_b_maybe(*b, start))
		ret = 1;
	return (ret);
}
