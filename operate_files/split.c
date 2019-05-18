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

static int	push(int *a_stk, t_tack *a, int *b_stk, t_tack *b)
{
	int i;

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

static void	rotate(int *stk, int len)
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

static void	reverse_rotate(int *stk, int len)
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

static void	do_thing(char *s, char **solution, t_tack *a, t_tack *b)
{
	if (s[0] == 'r' && s[1] == 'a')
	{
		*solution = ft_strfajoin(solution, "ra.\n");
		rotate(a->stack, a->length);
	}
	else if (s[0] == 'p' && s[1] == 'a')
	{
		*solution = ft_strfajoin(solution, "pa.\n");
		push(a->stack, a, b->stack, b);
	}
	else if (s[0] == 'p' && s[1] == 'b')
	{
		*solution = ft_strfajoin(solution, "pb.\n");
		push(b->stack, b, a->stack, a);
	}
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a')
	{
		*solution = ft_strfajoin(solution, "rra\n");
		reverse_rotate(a->stack, a->length);
	}
}

void		split(t_tack *a, t_tack *b, int width, char **solution)
{
	int	i;
	int	*stack;

	int pivot;

	pivot = 0;
	i = a->length - 1;
	while (i > 0 && a->stack[i - 1] == a->stack[i] - 1)
		i--;
	if (a->stack[i] == 0)
		pivot = a->length - 1 - i;
	pivot += width / 2 + b->length;
	if (width > a->length)
		width = a->length;
	stack = a->stack;
	i = 0;
	while (i < width)
	{
		if (stack[i] < pivot)
			do_thing("ra", solution, a, b);
		else
			do_thing("pb", solution, a, b);
		i++;
	}
	while (i > 0)
	{
		if (i < pivot)
			do_thing("pa", solution, a, b);
		else
			do_thing("rra", solution, a, b);
		i--;
	}
}
