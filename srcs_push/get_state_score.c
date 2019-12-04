/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_state_score.c                                   :+:    :+:           */
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
/*
**static void	get_distances(t_array a, char name, int *distances)
**{
**	int i;
**
**	i = 0;
**	while (i < a.len)
**	{
**		if (name == 'a')
**			distances[i] = i - count_smaller(a.stack[i]);
**		else if (name == 'b')
**			distances[i] = (a.len - 1 - i) - count_smaller(a.stack[i]);
**		i++;
**	}
**}
**
**static int	rotation_score(int *distances, int len)
**{
**	int i;
**	int sum;
**	int average;
**
**	sum = 0;
**	i = 0;
**	while (i < len)
**	{
**		sum += distances[i];
**		i++;
**	}
**	average = (sum + (len / 2)) / len;
**	while (i >= 0)
**	{
**		distances[i] -= average;
**		i--;
**	}
**	return (average);
**}
**
**static int	distance_score(int *distances, int len)
**{
**	int i;
**	int sum;
**
**	sum = 0;
**	i = 0;
**	while (i < len)
**	{
**		sum += ft_abs(distances[i]) + 2;
**		i++;
**	}
**	return (sum);
**}
*/
/*
** Justification: every int in b needs to be pushed to a and
** rotated out of the way.
** When dealing with big stacks it is likely the entire stack will
** need to be rotated through.
*/

// int			select_score(t_array a, char stck, int mod)
// {
// 	int *j;
// 	int i;
// 	int ofs;
// 	int min;

// 	if (a.len <= 2)
// 		return (0);
// 	min = INT32_MAX;
// 	j = malloc(sizeof(int) * a.len);
// 	if (!j)
// 		ft_error("MALLOC FAILED\n");
// 	i = 0;
// 	while (i < a.len)
// 	{
// 		j[i] = 2;
// 		ofs = mod - a.stack[i];
// 		while (j[i] < a.len && ((stck == 'a' &&
// 		(a.stack[j[i] - 1] + ofs) % mod < a.stack[j[i]] % mod) || (stck == 'b'
// 		&& (a.stack[j[i] - 1] + ofs) % mod < a.stack[j[i]] % mod)))
// 			j[i]++;
// 		if (j[i] < min)
// 			min = j[i];
// 		i++;
// 	}
// 	return ((a.len - min) * 3);
// }

static int	merge_score(t_node node)
{
	return (node.b->len);
}

int			inversion_score(t_array arr, char stck)
{
	int i;
	int j;
	int inver;

	inver = 0;
	i = 0;
	while (i + 1 < arr.len)
	{
		j = i + 1;
		while (j < arr.len)
		{
			if (stck == 'a' && arr.stack[i] > arr.stack[j])
				inver++;
			else if (stck == 'b' && arr.stack[i] < arr.stack[j])
				inver++;
			j++;
		}
		i++;
	}
	return (inver);
}

void		get_state_score(t_node *node)
{
	int score;

	score = 0;
	node->score_a = inversion_score(*(node->a), 'a');
	node->score_b = inversion_score(*(node->b), 'b');
	if (node->b->len > 0 || node->score_a > 0)
		node->weight = node->score_a + node->score_b +
											merge_score(*node) + node->n_instr;
	else
		node->weight = 0;
}
