/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 15:02:59 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/25 15:02:59 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotate(int *stk, int len)
{
	int temp;
	int i;

	temp = stk[0];
	i = 0;
	while (i <= len - 2)
	{
		stk[i] = stk[i + 1];
		i++;
	}
	stk[len - 1] = temp;
}

void	reverse_rotate(int *stk, int len)
{
	int temp;
	int i;

	temp = stk[len - 1];
	i = len - 2;
	while (i >= 0)
	{
		stk[i + 1] = stk[i];
		i--;
	}
	stk[0] = temp;
}

void	swap(t_tack stk)
{
	int temp;

	if (stk.length >= 2)
	{
		temp = stk.stack[0];
		stk.stack[0] = stk.stack[1];
		stk.stack[1] = temp;
	}
}

int		push(t_tack *a, t_tack *b)
{
	int i;
	int *a_stk;
	int *b_stk;

	if (b->length <= 0)
		return (0);
	a_stk = a->stack;
	b_stk = b->stack;
	i = a->length - 1;
	while (i >= 0)
	{
		a_stk[i + 1] = a_stk[i];
		i--;
	}
	a_stk[0] = b_stk[0];
	a->length++;
	i = 0;
	while (i <= b->length - 2)
	{
		b_stk[i] = b_stk[i + 1];
		i++;
	}
	b->length--;
	return (1);
}
