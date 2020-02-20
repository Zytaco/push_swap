/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inversion_score.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 10:15:52 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/05 10:15:53 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			rot_distance(int dist, int len)
{
	return ((len - ft_abs((2 * ft_abs(dist)) - len)) / 2);
}

static int cmp(int a, int b, char stck)
{
	if (stck == 'a')
		return (a < b);
	else if (stck == 'b')
		return (a > b);
	else
		ft_error("Wtf, what stack did you give to cmp?");
	return (-1);
}

// int			inversion_score(int *st, int len, char stck)
// {
// 	int i;
// 	int j;
// 	int inver;

// 	if (len <= 1)
// 		return (0);
// 	inver = 0;
// 	i = 1;
// 	while (i == 1 || i < (len - 1) / 2)
// 	{
// 		j = 0;
// 		while (j < len)
// 		{
// 			if (!cmp(st[j], st[(j + i) % len], stck))
// 				inver += 2;
// 			j++;
// 		}
// 		inver -= 2 * i;
// 		i++;
// 	}
// 	return (inver);
// }

// int			new_inversion_score(t_tack st, char stack)
// {
	// U int	i;
	// int		inver;
	// U int	dest;
// 
	// if (st.size <= 1)
		// return (0);
	// inver = 0;
	// i = 0;
	// while (i < st.size)
	// {
		// if (stack == 'a')
			// dest = count_smaller(st.stack[i], st);
		// else
			// dest = count_bigger(st.stack[i], st);
		// if (dest != i)
		// {
			// inver += 2 * rot_distance(ft_abs(i - dest), st.size);
		// }
		// i++;
	// }
	// return (inver);
// }

int			inversion_score(t_tack st, char stck)
{
	size_t	i;
	int		inver;

	if (st.size <= 1)
		return (0);
	inver = 0;
	i = 0;
	while (i < st.size - 1)
	{
		if (!cmp(st.stack[i], st.stack[i + 1], stck))
			inver += 2;
		i++;
	}
	return (inver);
}

int			swap_score(t_tack st, char stck)
{
	size_t	i;
	size_t	j;
	int		inver;

	if (st.size <= 1)
		return (0);
	inver = 0;
	i = 0;
	while (i < st.size - 1)
	{
		j = i + 1;
		while (j < st.size)
		{
			if (!cmp(st.stack[i], st.stack[j], stck))
				inver += 1;
			j++;
		}
		i++;
	}
	return (inver);
}

// t_stacks		stacks_cuts(t_stacks stacks)
// {
// 	size_t	i;
// 	// t_tack	temp_a;
// 	// t_tack	temp_b;

// 	display_node((t_node){NULL, NULL, stacks, NULL, -100, -100});
// 	// temp_a = stacks.a;
// 	// temp_b = stacks.b;
// 	// stacks.a = stacks.a_dest;
// 	// stacks.b = stacks.b_dest;
// 	// display_node((t_node){NULL, NULL, stacks, NULL, -100, -100});
// 	// stacks.a = temp_a;
// 	// stacks.b = temp_b;
// 	while (stacks.a.size > 0 &&
// 	(U int)stacks.a_dest.stack[stacks.a.size - 1] ==
// 												stacks.a.size + stacks.b.size)
// 		stacks.a.size--;
// 	ft_printf("comparing %u vs %u\n", (U int)stacks.a_dest.stack[stacks.a.size - 1], stacks.a.size + stacks.b.size);
// 	ft_printf("a cut end: %d\n", stacks.a.size);
// 	while (stacks.b.size > 0 &&
// 	(U int)stacks.b_dest.stack[stacks.b.size - 1] == (stacks.a_dest.size +
// 	stacks.b_dest.size) - (stacks.a.size + stacks.b.size))
// 	{
// 		stacks.score_b += 1;
// 		stacks.b.size--;
// 	}
// 	ft_printf("b cut end: %d\n", stacks.b.size);
// 	i = 0;
// 	while (i < stacks.b.size &&
// 	(U int)stacks.b_dest.stack[i] == (stacks.a_dest.size +
// 	stacks.b_dest.size) - (stacks.a.size + stacks.b.size + i))
// 		i++;
// 	ft_printf("b cut start: %d\n\n\n", i);
// 	stacks.score_b += 2 * rot_distance(i, stacks.b_dest.size);
// 	stacks.b.stack += i;
// 	stacks.b_dest.stack += i;
// 	stacks.b.size -= i;
// 	stacks.a_dest.size = stacks.a.size;
// 	stacks.b_dest.size = stacks.b.size;
// 	return (stacks);
// }

// int			worst_case_score(t_tack st, char stck)
// {
// 	size_t start;
// 	size_t len;

// 	start = 0;
// 	while (start < st.size - 1 && st.stack[start] ==
// 								get_lowest(st.stack + start, st.size - start))
// 		start++;
// 	if (start == st.size - 1)
// 		return (0);
// }

// int			insert_score(t_tack st, char stck)
// {
// 	size_t i;
// 	int dest;
// 	int score;

// 	score = 0;
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (stck == 'a')
// 			dest = count_smaller(st.stack[i], st);
// 		else
// 			dest = count_bigger(st.stack[i], st);
// 		score += 2 + 2 * rot_distance(ft_abs(i - dest), stack.len);
// 		i++;
// 	}
// 	return (score);
// }

// int			rot_match_score(t_tack st, char stck)
// {
// 	size_t i;
// 	size_t offset;
// 	int score;

// 	score = 0;
// 	offset = 0;
// 	while ()
// 	{

// 		offset++;
// 	}
// }
