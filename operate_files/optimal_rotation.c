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

int		swap_maybe(t_tack stack, t_word *start, char name)
{
	int len;
	int *stk;

	len = stack.length;
	stk = stack.stack;
	if (len < 2 ||
	(stk[0] + 1) % len == stk[1] ||
	(stk[len - 1] + 1) % len == stk[0])
		return (0);
	if ((stk[1] + 1) % len == stk[len - 1] ||
	(len >= 3 &&
	(stk[0] + 1) % len == stk[2]))
	{
		swap(stack);
		if (name == 'a')
			new_to_list(start, "sa.");
		if (name == 'b')
			new_to_list(start, "sb.");
		return (1);
	}
	return (0);
}

void	rotation(t_tack a, int i, t_word *list, char name)
{
	int *stk;

	stk = a.stack;
	if (i > a.length / 2)
		i -= a.length;
	while (i > 0)
	{
		swap_maybe(a, list, name);
		if (name == 'a')
			new_to_list(list, "ra.");
		if (name == 'b')
			new_to_list(list, "rb.");
		rotate(a.stack, a.length);
		i--;
	}
	while (i < 0)
	{
		swap_maybe(a, list, name);
		if (name == 'a')
			new_to_list(list, "rra");
		if (name == 'b')
			new_to_list(list, "rrb");
		reverse_rotate(a.stack, a.length);
		i++;
	}
}

void		optimal_rotation(t_tack a, t_word *list, char name)
{
	int i;
	int *stk;
	int start;

	stk = a.stack;
	i = 0;
	start = -1;
	while (start == -1)
	{
		if (stk[i] == 0)
			start = i;
		i++;
	}
	i--;
	if (stk[(i + 1) % a.length] == stk[i % a.length] + 1)
		i++;
	while (stk[(i + 1) % a.length] % a.length ==
	(stk[i % a.length] + 1) % a.length &&
	i % a.length != start)
		i++;
	i++;
	i %= a.length;
	rotation(a, i, list, name);
}

int			rotate_a_maybe(t_tack a, t_word *list)
{
	int i;
	int *stk;
	int start;

	stk = a.stack;
	i = 0;
	start = -1;
	while (start == -1)
	{
		if (stk[i] == 0)
			start = i;
		i++;
	}
	i--;
	if (stk[(i + 1) % a.length] == stk[i % a.length] + 1)
		i++;
	while (stk[(i + 1) % a.length] % a.length ==
	(stk[i % a.length] + 1) % a.length &&
	i % a.length != start)
		i++;
	if ((i % (a.length / 2)) > ((i - start) % a.length))
	{
		rotation(a, i, list, 'a');
		return (1);
	}
	return (0);
}

int			find_biggest(int *stk, int len)
{
	int i;
	int biggest;

	if (len <= 0)
		return (-1);
	biggest = stk[0];
	i = 1;
	while (i < len)
	{
		if (stk[i] > biggest)
			biggest = stk[i];
		i++;
	}
	return (biggest);
}

int			rotate_b_maybe(t_tack b, t_word *list, int biggest)
{
	int i;
	int *stk;
	int start;

	stk = b.stack;
	i = 0;
	start = -1;
	while (start == -1 && i < b.length)
	{
		if (stk[i] == biggest)
			start = i;
		else
			i++;
	}
	while (stk[i % b.length] - 1 == stk[(i + 1) % b.length])
		i++;
	if ((i % (b.length / 2)) > ((i - start) % b.length))
	{
		rotation(b, i, list, 'b');
		return (1);
	}
	return (0);
}
