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

void	order_three_b(int *stk, t_tack *a, t_tack *b, t_word *start)
{
	int low;
	int big;

	low = find_lowest(stk, 3);
	big = find_bigest(stk, 3);
	if (stk[0] != low && stk[1] != big)
		do_thing_b("sb.", start, a, b);
	if (stk[2] == big)
		return ;
	do_thing_b("rb.", start, a, b);
	do_thing_b("sb.", start, a, b);
	do_thing_b("rrb", start, a, b);
	if (stk[0] != low)
		do_thing_b("sb.", start, a, b);
}

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
