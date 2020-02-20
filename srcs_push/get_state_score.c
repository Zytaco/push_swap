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

int			distance_score(t_tack a, t_tack ord_a)
{
	size_t	i;
	int		pos;
	int		score;
	int		ignore;

	ignore = 0;
	score = 0;
	i = 0;
	while (i < a.size)
	{
		pos = get_pos(ord_a.stack[i], a);
		if (pos != -1)
			score += ft_abs(pos - i);
		else
			ignore++;
		i++;
	}
	return (score);
}

static int	rot_score(t_tack st, char stack)
{
	return (rot_distance(((stack == 'a') ? get_lowest(st.stack, st.size)
							: get_highest(st.stack, st.size)), (int)st.size));
}

static int	get_score_a(t_tack a)
{
	const int inver_score = inversion_score(a, 'a');

	if (inver_score == 0)
		return (rot_score(a, 'a'));
	else
		return (inver_score);
}

static int	get_score_b(t_stacks stacks, t_data data)
{
	const t_tack	b = stacks.b;
	const int		inver_score = inversion_score(b, 'b');
	int				merge_score;

	while (b.size > 0 && b.stack[0] == data.smallest)

	merge_score = 2 * b.size;
	if (inver_score == 0)
		return (rot_score(b, 'b') + merge_score);
	else
		return (inver_score + merge_score);
}

static t_stacks	cuts(t_stacks stacks, t_data data)
{
	while (1)
	{
		if (stacks.a.size > 0 && stacks.a.stack[stacks.a.size - 1] == data.biggest)
		{
			stacks.a.size--;
			data.biggest--;
			stacks.score_a += 1;
		}
		else if (stacks.a.size > 0 && stacks.a.stack[0] == data.smallest)
		{
			stacks.a.stack++;
			stacks.a.size--;
			data.smallest++;
		}
		else if (stacks.a.size > 1 && stacks.a.stack[1] == data.smallest && stacks.a.stack[0] == data.smallest + 1)
		{
			stacks.a.stack += 2;
			stacks.a.size -= 2;
			data.smallest += 2;
			stacks.score_a += 1;
		}
		else if (stacks.a.size > 1 && stacks.a.stack[1] == data.smallest && stacks.a.stack[0] == data.smallest + 1)
		{
			stacks.a.size -= 2;
			data.biggest -= 2;
			stacks.score_a += 3;
		}
		else if (stacks.b.size > 0 && stacks.b.stack[stacks.b.size - 1] == data.smallest)
		{
			stacks.b.size--;
			data.smallest++;
			stacks.score_b += 1;
		}
		else if (stacks.b.size > 0 && stacks.b.stack[0] == data.biggest)
		{
			stacks.b.stack++;
			stacks.b.size--;
			data.biggest--;
			stacks.score_b += 2;
		}
		else if (stacks.b.size > 1 && stacks.b.stack[stacks.b.size - 1] == data.smallest - 1 && stacks.b.stack[stacks.b.size - 2] == data.smallest)
		{
			stacks.b.size -= 2;
			data.smallest += 2;
			stacks.score_b += 3;
		}
		else if (stacks.b.size > 1 && stacks.b.stack[1] == data.smallest && stacks.b.stack[0] == data.biggest - 1)
		{
			stacks.b.stack += 2;
			stacks.b.size -= 2;
			data.smallest += 2;
			stacks.score_b += 5;
		}
		else
			return (stacks);
	}
}

void		get_weight(t_node *node, t_data data)
{
	data.max_depth = ft_min(data.max_depth, INT32_MAX);
	if (node->stacks.a.size <= 1)
		node->stacks.score_a = 0;
	else
		node->stacks.score_a = get_score_a(node->stacks.a, data);
	if (node->stacks.b.size <= 0)
		node->stacks.score_b = 0;
	else
		node->stacks.score_b = get_score_b(node->stacks, data);
	node->weight = node->stacks.score_a + node->stacks.score_b;
}
