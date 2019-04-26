/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 14:48:47 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/22 14:48:48 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "operate.h"

/*
** The return value is to ensure reversability of operations, to prevent
** the reverse of a function doing something if the funtion doesn't.
*/

static void	swap(t_tack *stk)
{
	int temp;

	if (stk->length >= 2)
	{
		temp = stk->stack[0];
		stk->stack[0] = stk->stack[1];
		stk->stack[1] = temp;
	}
}

static int	push(t_tack *a, t_tack *b)
{
	int i;

	if (b->length <= 0)
		return (0);
	i = a->length - 1;
	while (i >= 0)
	{
		a->stack[i + 1] = a->stack[i];
		i--;
	}
	a->stack[0] = b->stack[0];
	a->length++;
	i = 0;
	while (i <= b->length - 2)
	{
		b->stack[i] = b->stack[i + 1];
		i++;
	}
	b->length--;
	return (1);
}

static void	rotate(t_tack *stk)
{
	int temp;
	int i;

	temp = stk->stack[0];
	i = 0;
	while (i <= stk->length - 2)
	{
		stk->stack[i] = stk->stack[i + 1];
		i++;
	}
	stk->stack[stk->length - 1] = temp;
}

int			operate(char *line, int i, t_tack *a, t_tack *b)
{
	if ((i == -1 && ft_strcmp(line, "sa") == 0) || i == 0)
		swap(a);
	else if ((i == -1 && ft_strcmp(line, "sb") == 0) || i == 1)
		swap(b);
	else if ((i == -1 && ft_strcmp(line, "ss") == 0) || i == 2)
	{
		swap(a);
		swap(b);
	}
	else if ((i == -1 && ft_strcmp(line, "pa") == 0) || i == 3)
		return (push(a, b));
	else if ((i == -1 && ft_strcmp(line, "pb") == 0) || i == 4)
		return (push(b, a));
	else if ((i == -1 && ft_strcmp(line, "ra") == 0) || i == 5)
		rotate(a);
	else if ((i == -1 && ft_strcmp(line, "rb") == 0) || i == 6)
		rotate(b);
	else if ((i == -1 && ft_strcmp(line, "rr") == 0) || i == 7)
	{
		rotate(a);
		rotate(b);
	}
	else
		operate_helper(line, i, a, b);
	return (1);
}
