/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge_split.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 15:38:21 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/22 15:38:22 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	split(t_array *subseq, t_data *data, char stck)
{
	int pos;
	int len;

	len = LEN - S_LEN;
	while (len > 0)
	{
		pos = get_pos(*subseq, ELE(0));
		if (pos == -1)
		{
			PUSH;
			len--;
		}
		else
			ROTATE;
	}
}

int		put_in_subs_check(t_array *subseq, t_data *data, char stck, int pos)
{
	if (stck == 'b' && (S_LEN == 1 || (
	(S_ELE(pos) > ELE(0) && ELE(0) > S_ELE(pos + 1)) ||
	((S_ELE(pos) < S_ELE(pos + 1) &&
	(ELE(0) < S_ELE(pos) || S_ELE(pos + 1) < ELE(0)))))))
		return (1);
	return (0);
}

void	put_in_subs(t_array *subseq, t_data *data, char stck, int pos)
{
	int i;

	sa(data, 1);
	i = S_LEN - 1;
	S_LEN++;
	while (i >= pos)
	{
		S_ELE(i + 1) = S_ELE(i);
		i--;
	}
	S_ELE(pos) = ELE(0);
}

void	swap_maybe(t_array *subseq, t_data *data, char stck, int *len)
{
	if (S_LEN < 1 || get_pos(*subseq, ELE(1)) == -1)
		return ;
	if (put_in_subs_check(subseq, data, stck, 0))
	{
		put_in_subs(subseq, data, stck, 0);
		(*len)++;
	}
}

void	merge(t_array dump, t_data *data, char stck)
{
	int len;

	len = dump.len;
	while (len > 0)
	{
		while (get_pos(dump, ELE(0)) == -1)
			ROTATE;
		while (!((O_ELE(-1) < ELE(0) && ELE(0) < O_ELE(0)) ||
		(O_ELE(0) < O_ELE(-1) && (ELE(0) > O_ELE(-1) || ELE(0) < O_ELE(0)))))
		{
			display_array(data->a, "a afer rot");
			display_array(data->b, "b afer rot");
			O_ROTATE;
		}
		PUSH;
		len--;
	}
}
