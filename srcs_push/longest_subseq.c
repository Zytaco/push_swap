/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   longest_subseq.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 11:33:57 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/19 11:33:57 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Steps stores the maximum amount of steps that can be taken from start
** to the index in the context of making an increasing subsequence.
**
** Prev stores the index of the previous int in an increasing subseq.
*/

t_array		*make_longest_subseq(t_array arr, t_subseq subseq)
{
	int		pos;
	int		i;
	t_array	*ret;

	i = 0;
	pos = arr.len - 1;
	while (i < arr.len)
	{
		if (subseq.steps[IND(i)] > subseq.steps[IND(pos)])
			pos = i;
		i++;
	}
	ret = new_array(subseq.steps[IND(pos)] + 1);
	while (pos >= 0)
	{
		ret->stack[pos] = arr.stack[IND(pos)];
		pos = subseq.prev[IND(pos)];
	}
	return (ret);
}

void		analyze_stack(t_array arr, t_subseq subseq, char stack)
{
	int i;
	int j;

	i = 0;
	while (i < arr.len)
	{
		subseq.steps[IND(i)] = 0;
		j = i - 1;
		while (j >= 0)
		{
			if (SIZE_CMP && subseq.steps[IND(j)] + 1 > subseq.steps[IND(i)])
			{
				subseq.steps[IND(i)] = subseq.steps[IND(j)] + 1;
				subseq.prev[IND(i)] = j;
			}
			j--;
		}
		i++;
	}
}

t_array		*find_longest_subseq(t_array arr, char stack)
{
	t_subseq	subseq;
	t_array		*temp;
	t_array		*ret;

	subseq.offset = 0;
	ret = NULL;
	subseq.steps = malloc(sizeof(int) * arr.len);
	subseq.prev = malloc(sizeof(int) * arr.len);
	subseq.prev[0] = -1;
	while (subseq.offset < arr.len)
	{
		analyze_stack(arr, subseq, stack);
		temp = make_longest_subseq(arr, subseq);
		if (!ret || temp->len > ret->len)
		{
			if (ret)
				free(ret);
			ret = temp;
		}
		else
			free(temp);
		subseq.offset++;
	}
	return (ret);
}
