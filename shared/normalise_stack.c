/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalise_stack.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 18:05:03 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/14 18:05:03 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		count_smaller(int x, t_tack st)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	while (i < st.size)
	{
		if (st.stack[i] < x)
			count++;
		i++;
	}
	return (count);
}

t_tack			normalize(t_tack st)
{
	t_tack norm;

	norm.stack = ft_memalloc(sizeof(int) * st.size);
	norm.size = 0;
	while (norm.size < st.size)
	{
		norm.stack[norm.size] = count_smaller(st.stack[norm.size], st);
		norm.size++;
	}
	ft_free(st.stack);
	return (norm);
}

int		get_lowest(int *st, int len)
{
	int min_pos;
	int i;

	min_pos = 0;
	i = 1;
	while (i < len)
	{
		if (st[i] < st[min_pos])
			min_pos = i;
		i++;
	}
	return (min_pos);
}

int		get_highest(int *st, int len)
{
	int max_pos;
	int i;

	max_pos = 0;
	i = 1;
	while (i < len)
	{
		if (st[i] > st[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}
