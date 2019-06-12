/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_help.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 13:25:11 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/09 13:25:11 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "simple_help.h"

void	shuffle_swap(t_tack stk, char name, t_word *start)
{
	if (stk.length < 2)
		return;
	if (stk.stack[0] > stk.stack[1])
	{
		swap(stk);
		if (name == 'a')
				new_to_list(start, "sa.");
		if (name == 'b')
				new_to_list(start, "sb.");
	}
}

int			find_lowest(int *stk, int len)
{
	int lowest;
	int i;

	lowest = stk[0];
	i = 1;
	while (i < len)
	{
		if (stk[i] < lowest)
			lowest = stk[i];
		i++;
	}
	return (lowest);
}

/*
** find = 0 will work on stack a any other number will work on stack b.
*/

int			tail_a(int *stk, int len)
{
	int i;

	if (stk[len - 1] != find_biggest(stk, len))
		return (0);
	i = 1;
	while (i < len && stk[len - 1 - i] + 1 == stk[len - i])
		i++;
	return (i);
}

int			tail_b(int *stk, int len)
{
	int i;

	if (stk[len - 1] != 0)
		return (0);
	i = 1;
	while (i < len && stk[len - 1 - i] - 1 == stk[len - i])
		i++;
	return (i);
}

void		lowest_to_front(t_tack a, t_word *start)
{
	int i;
	int lowest;
	int *stk;
	int len;

	stk = a.stack;
	len = a.length;
	lowest = find_lowest(stk, len);
	i = 0;
	while (i < len && stk[i] != lowest)
		i++;
	rotation_a(a, i, start);
}

int			ordered_a(int *stk, int len)
{
	int i;
	int lowest;

	lowest = find_lowest(stk, len);
	if (len <= 0)
		return (1);
	i = len - 1;
	if (len > 2 && stk[i] > stk[0] && stk[0] != lowest)
		return (0);
	while (i > 0)
	{
		i--;
		if (stk[i] > stk[i + 1] && !(stk[i + 1] == lowest))
			return (0);
	}
	return (1);
}

int			ordered_b(int *stk, int len)
{
	int i;
	int biggest;

	biggest = find_biggest(stk, len);
	if (len <= 0)
		return (1);
	i = len - 1;
	if (len > 2 && stk[i] < stk[0] && stk[0] != biggest)
		return (0);
	while (i > 0)
	{
		i--;
		if (stk[i] < stk[i + 1] && !(stk[i + 1] == biggest))
			return (0);
	}
	return (1);
}
