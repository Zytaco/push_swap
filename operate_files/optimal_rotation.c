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

int		swap_a_maybe(t_tack a, t_word *start, int mod)
{
	int len;
	int *stk;

	len = a.length;
	stk = a.stack;
	if (len <= 1 || (len >= 3 &&
	((stk[0] + 1) % len == stk[1] % len ||
	((stk[len - 1] + 1) % len == stk[0] % len) ||
	(stk[len - 1] % len == (stk[0] - 1) % len) ||
	(stk[0] % len == (stk[1] - 1) % len))))
		return (0);
	if ((stk[1] + 1) % len == stk[len - 1] % len ||
	(len >= 3 && (stk[0] + 1) % len == stk[2] % len) ||
	(len <= 4 && stk[0] - 1 == stk[1]))
	{
		swap(a);
		if (len >= 3 && (stk[0] + 1) % len == stk[2] % len)
		{
			new_to_list(start, "->.");
			printf("len %d\n", len);
		}
		new_to_list(start, "sa.");
		if (len >= 3 && (stk[0] + 1) % len == stk[2] % len)
			new_to_list(start, "<-.");
		return (1);
	}
	return (0);
}

int		swap_b_maybe(t_tack b, t_word *start, int mod)
{
	int len;
	int *stk;

	len = b.length;
	stk = b.stack;
	if (len <= 1 || (len >= 3 &&
	((stk[0] + 1) % len == stk[1] % len ||
	((stk[len - 1] + 1) % len == stk[0] % len) ||
	(stk[len - 1] % len == (stk[0] - 1) % len) ||
	(stk[0] % len == (stk[1] - 1) % len))))
		return (0);
	if ((stk[1] - 1) % len == stk[len - 1] % len ||
	(len >= 3 &&
	(stk[0] - 1) % len == stk[2] % len) ||
	(len <= 4 && stk[0] + 1 == stk[1]))
	{
		swap(b);
		new_to_list(start, "sb.");
		return (1);
	}
	return (0);
}

void	rotation(t_tack st, int i, t_word *list, char name)
{
	int *stk;

	stk = st.stack;
	if (i > st.length / 2)
		i -= st.length;
	while (i > 0)
	{
		if (name == 'a')
		{
			swap_a_maybe(st, list);
			new_to_list(list, "ra.");
		}
		if (name == 'b')
		{
			swap_b_maybe(st, list);
			new_to_list(list, "rb.");
		}
		rotate(st.stack, st.length);
		i--;
	}
	while (i < 0)
	{
		if (name == 'a')
		{
			swap_a_maybe(st, list);
			new_to_list(list, "rra");
		}
		if (name == 'b')
		{
			swap_b_maybe(st, list);
			new_to_list(list, "rrb");
		}
		reverse_rotate(st.stack, st.length);
		i++;
	}
}

void		optimal_rotation(t_tack a, t_word *list, char name)
{
	int i;
	int *stk;
	int start;

	if (a.length <= 0)
		return ;
	stk = a.stack;
	i = 0;
	start = -1;
	while (start == -1)
	{
		if (stk[i] == 0)
			start = i;
		else
			i++;
	}
	printf("i before: %d\n", i % a.length);
	if (a.length > 1 && stk[(i + 1) % a.length] == stk[i % a.length] + 1)
		i++;
	while (stk[(i + 1) % a.length] % a.length ==
	(stk[i % a.length] + 1) % a.length &&
	stk[(i - 1) % a.length] != 0)
		i++;
	printf("i after: %d\n", i);
	i++;
	i %= a.length;
	rotation(a, i, list, name);
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

int			rotate_a_maybe(t_tack a, t_word *list)
{
	int i;
	int *stk;
	int start;

	if (a.length <= 1)
		return (0);
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
	swap_a_maybe(a, list);
	return (0);
}

int			rotate_b_maybe(t_tack b, t_word *list, int biggest)
{
	int i;
	int *stk;
	int start;

	if (b.length <= 1)
		return (0);
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
	swap_b_maybe(b, list);
	return (0);
}
