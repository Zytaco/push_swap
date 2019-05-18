/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 09:57:03 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/15 09:57:03 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include <unistd.h>
#include <stdio.h>

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
	int *a_stk;
	int *b_stk;

	a_stk = a->stack;
	b_stk = b->stack;
	if (b->length <= 0)
		return (0);
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

static int	needs_split(int width, int *stk, int a_len, int b_len)
{
	int i;
	int pivot;

	pivot = 0;
	i = a_len - 1;
	while (i > 0 && stk[i - 1] == stk[i] - 1)
		i--;
	if (stk[i] == 0)
		pivot = a_len - 1 - i;
	pivot += width / 2 + b_len;
	while (i < pivot)
	{
		if (stk[i] >= pivot)
			return (1);
		i++;
	}
	return (0);
}

static void	push_four(t_tack *a, t_tack *b, char **solution)
{
	*solution = ft_strfajoin(solution, "pb.\n");
	push(b, a);
	*solution = ft_strfajoin(solution, "pb.\n");
	push(b, a);
	if (b->stack[1] > b->stack[0] && a->stack[0] > a->stack[1])
	{
		*solution = ft_strfajoin(solution, "ss.\n");
		swap(a);
		swap(b);
	}
	else
	{
		if (b->stack[1] > b->stack[0])
		{
			*solution = ft_strfajoin(solution, "sb.\n");
			swap(b);
		}
		else if (a->stack[0] > a->stack[1])
		{
			*solution = ft_strfajoin(solution, "sa.\n");
			swap(a);
		}
	}
	*solution = ft_strfajoin(solution, "pb.\n");
	push(b, a);
	*solution = ft_strfajoin(solution, "pb.\n");
	push(b, a);
}

static int	ordered(t_tack a)
{
	int *stk;
	int i;

	i = a.length - 1;
	stk = a.stack;
	if (stk[i + 1] > stk[0] && stk[0] != 0)
		return (0);
	while (i > 0)
	{
		i--;
		if (stk[i] > stk[i + 1] && !(stk[i + 1] == 0))
			return(0);
	}
	return (1);
}

void		push_remainder(t_tack *a, t_tack *b, char **solution)
{
	if (a->stack[0] > a->stack[1])
	{
		swap(a);
		*solution = ft_strfajoin(solution, "sa.\n");
	}
	while (b->length > 0)
	{
		push(a, b);
		*solution = ft_strfajoin(solution, "pa.\n");
	}
}

void		push_everything(t_tack *a, t_tack *b, char **solution)
{
	int i;

	i = 0;
	while (a->stack[i] != b->length)
		i++;
	if (i > a->length / 2)
		i = i - a->length;
	while (i > 0)
	{
		*solution = ft_strfajoin(solution, "ra.\n");
		i--;
	}
	while (i < 0)
	{
		*solution = ft_strfajoin(solution, "rra\n");
		i++;
	}
	i = b->length;
	while (i > 0)
	{
		*solution = ft_strfajoin(solution, "pa.\n");
		i--;
	}
}

/*
** optimal_rotaion is non functional, does nothing.
** pb 2
** ra 2
** rra 2
** pa 2
** must be reduced to nothing.
*/

void		solver(t_tack a, t_tack b, char **solution)
{
	int	width;

	optimal_rotation(a, solution);
	while (!ordered(a))
	{
		width = 4;
		while (width < a.length &&
		needs_split(width / 2, a.stack, a.length, b.length))
			width *= 2;
		while (width > 2)
		{
			if (width < a.length && width >= 4)
				split(&a, &b, width, solution);
			width /= 2;
		}
		if (needs_split(2, a.stack, a.length, b.length))
			split(&a, &b, 2, solution);
		if (a.length >= 4)
			push_four(&a, &b, solution);
		else
			push_remainder(&a, &b, solution);
	}
	push_everything(&a, &b, solution);
	write(1, "hey\n", 4);
	free(a.stack);
	free(b.stack);
}
