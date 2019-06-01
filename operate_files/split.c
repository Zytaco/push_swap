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

static void	do_thing(char *s, t_word *start, t_tack *a, t_tack *b)
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
	else if (s[0] == 'p' && s[1] == 'b')
	{
		new_to_list(start, "pb.");
		push(b, a);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
	{
		new_to_list(start, "rra");
		reverse_rotate(a->stack, a->length);
	}
}

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

/*
** Pushes the higher valued half within the width to b
** while rotating past the lower valued half.
** Then pushes everything back and then rotates everything back.
** Effectively everything within the width is split in half with everythin at
** or before half the width being smaller than everything after half the width.
*/


void		split(t_tack *a, t_tack *b, int width, t_word *start)
{
	int	i;
	int	*stack;
	int pivot;
	int a_len;

	stack = a->stack;
	a_len = tailles(stack, a->length);
	if (width > a_len)
		width = a_len;
	pivot = find_lowest(stack, tailles(stack, a->length)) + (width / 2);
	i = 0;
	while (i < width && i < a_len)
	{
		swap_maybe(*a, start, 'a');
		if (stack[0] < pivot)
			do_thing("ra", start, a, b);
		else
			do_thing("pb", start, a, b);
		swap_maybe(*b, start, 'b');
		i++;
	}
	while (b->length > 0)
		do_thing("pa", start, a, b);
}
