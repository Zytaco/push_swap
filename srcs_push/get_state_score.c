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

static int	rot_score(t_tack st, char stack)
{
	return (rot_distance(((stack == 'a') ? get_lowest(st.stack, st.size)
							: get_highest(st.stack, st.size)), (int)st.size));
}

static int	get_score_a(t_tack a)
{
	const int inver_score = inversion_score(a.stack, a.size, 'a');

	if (inver_score == 0)
		return (rot_score(a, 'a'));
	else
		return (inver_score);
}

static int	get_score_b(t_tack b)
{
	const int inver_score = inversion_score(b.stack, b.size, 'b');

	if (inver_score == 0)
		return (rot_score(b, 'b'));
	else
		return (inver_score);
}

static int	merge_score(t_stacks stacks)
{
	return (2 * stacks.b.size);
}

void		get_weight(t_node *node)
{
	node->stacks.score_a = get_score_a(node->stacks.a);
	node->stacks.score_b = get_score_b(node->stacks.b);
	node->weight = node->stacks.score_a + node->stacks.score_b +
									merge_score(node->stacks);
}
