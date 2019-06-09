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

int			tail_a_or_b(int *stk, int len, int find)
{
	int i;
	int zero;

	i = 0;
	while (i < len && stk[i] != find)
		i++;
	if (stk[i] != 0)
		return (0);
	zero = i;
	if (find == 0)
		while (i + 1 < len && stk[i] + 1 == stk[i + 1])
			i++;
	else
		while (i + 1 < len && stk[i] - 1 == stk[i + 1])
			i++;
	if (i + 1 == len)
		return (zero);
	return (0);
}

static void	lowest_to_front(t_tack a, t_word *start)
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

int			ordered(int *stk, int len)
{
	int i;
	int lowest;

	lowest = find_lowest(stk, len);
	if (len <= 0)
		return (0);
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
