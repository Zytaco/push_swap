/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_tools.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:51:10 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/09 12:51:11 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "a_tools.h"
#include <stdio.h>

void	do_thing_a(char *s, t_word *start, t_tack *a, t_tack *b)
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

int		swap_a_maybe(t_tack a, t_word *start)
{
	int l;
	int *stk;
	int low;
	int big;

	l = a.length;
	stk = a.stack;
	low = find_lowest(stk, l, l);
	big = find_biggest(stk, l, l);
	if (l < 2 || (l > 2 &&
	(stk[0] + 1 == stk[1] || stk[1] + 1 == stk[2] || stk[l - 1] + 1 == stk[0]
	|| (stk[0] == big && stk[1] == low) || (stk[1] == big && stk[2] == low) ||
	(stk[l - 1] == big && stk[0] == low))))
		return (0);
	if ((l == 2 && stk[0] > stk[1]) || (l > 2 &&
	(stk[0] - 1 == stk[1] || stk[1] - 1 == stk[2] || stk[l - 1] - 1 == stk[0]
	|| (stk[0] == low && stk[1] == big) || (stk[1] == low && stk[2] == big) ||
	(stk[l - 1] == low && stk[0] == big))))
	{
		do_thing_a("sa.", start, &a, NULL);
		return (1);
	}
	return (0);
}

int		rotate_a_maybe(t_tack a, t_word *list)
{
	int i;
	int *stk;
	int start;

	if (a.length <= 1)
		return (0);
	stk = a.stack;
	i = 0;
	while (stk[i] != 0)
		i++;
	start = i;
	i--;
	if (stk[(i + 1) % a.length] == stk[i % a.length] + 1)
		i++;
	while (stk[(i + 1) % a.length] % a.length ==
	(stk[i % a.length] + 1) % a.length &&
	i % a.length != start)
		i++;
	if ((i % (a.length / 2)) > ((i - start) % a.length))
	{
		rotation_a(a, i, list);
		return (1);
	}
	swap_a_maybe(a, list);
	return (0);
}

/*
** shuffle sort is best when there's a tail and the stack <= 4
** for an unsorted length of L it needs to be done L / 2 to sort it.
*/
