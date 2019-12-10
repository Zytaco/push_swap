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

int			rot_distance(int dist, int len)
{
	return ((len - ft_abs((2 * ft_abs(dist)) - len)) / 2);
}

static int	merge_score(t_array a, t_array b)
{
	const int	a_min = a.stack[get_min_pos(a.stack, a.len)];
	int			i;
	int			merge_score;

	merge_score = 0;
	i = 0;
	while (i < b.len)
	{
		if (b.stack[i] < a_min)
			merge_score += 1;
		else
			merge_score += 2;
		i++;
	}
	return (merge_score);
}

void		get_state_score(t_node *node, t_array a, t_array b)
{
	node->score_a = 0;
	node->score_b = 0;
	node->weight = 0;
	if (a.len > 1)
	{
		node->score_a = inversion_score(a.stack, a.len, 'a');
		if (node->score_a <= 0)
			node->weight +=
			rot_distance(get_min_pos(a.stack, a.len) - 0, a.len);
		else
			node->score_a += a.len / 2;
	}
	if (b.len > 1)
	{
		node->score_b = inversion_score(b.stack, b.len, 'b');
		if (node->score_b <= 0)
			node->weight +=
			rot_distance(get_max_pos(b.stack, b.len) - 0, b.len);
		else
			node->score_b += b.len / 2;
	}
	if (b.len > 0 || node->score_a > 0 || node->weight > 0)
	{
		node->weight = node->score_a + node->score_b +
		node->n_instr + merge_score(a, b);
	}
	else
		node->weight = INT32_MIN + node->n_instr;
}
