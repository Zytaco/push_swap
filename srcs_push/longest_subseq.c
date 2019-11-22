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

static t_array	*make_longest_subseq(t_array arr, t_subseq subseq)
{
	int		pos;
	int		i;
	t_array	*ret;
	t_array steps;

	steps.stack = subseq.steps;
	steps.len = arr.len;
	pos = get_max_pos(steps);
	ret = new_array(arr.len);
	ret->len = subseq.steps[pos] + 1;
	i = subseq.steps[pos];
	while (i >= 0)
	{
		ret->stack[i] = arr.stack[IND(pos)];
		i--;
		pos = subseq.prev[pos];
	}
	return (ret);
}

static void		analyzestck(t_array arr, t_subseq subseq, char stck)
{
	int i;
	int j;

	i = 0;
	while (i < arr.len)
	{
		subseq.prev[i] = -1;
		subseq.steps[i] = 0;
		j = 0;
		while (j < i)
		{
			if (subseq.steps[j] + 1 > subseq.steps[i] &&
			((stck == 'a' && SIZE(arr.stack[IND(j)]) < SIZE(arr.stack[IND(i)]))
			||
			(stck == 'b' && SIZE(arr.stack[IND(j)]) > SIZE(arr.stack[IND(i)]))))
			{
				subseq.steps[i] = subseq.steps[j] + 1;
				subseq.prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

t_array			*find_longest_subseq(t_array arr, char stck)
{
	t_subseq	subseq;
	t_array		*temp;
	t_array		*ret;

	ret = NULL;
	subseq.steps = malloc(sizeof(int) * arr.len);
	subseq.prev = malloc(sizeof(int) * arr.len);
	subseq.offset = 0;
	while (subseq.offset < arr.len)
	{
		subseq.start = arr.stack[subseq.offset];
		analyzestck(arr, subseq, stck);
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
