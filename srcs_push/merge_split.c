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

void	split(t_array dump, t_data *data, char _stack)
{
	int pos;
	int len;

	len = LEN - dump.len;
	while (len > 0)
	{
		pos = get_pos(dump, STACK[0]);
		if (pos == -1)
		{
			PUSH;
			len--;
		}
		else
			ROTATE;
	}
}

void	merge(t_array dump, t_data *data, char _stack)
{
	int len;

	len = dump.len;
	while (len > 0)
	{
		while (get_pos(dump, STACK[0]) == -1)
			ROTATE;
		while (!
		((O_STACK[O_LEN - 1] < STACK[0] && STACK[0] < O_STACK[0]) ||
		(O_STACK[0] < O_STACK[O_LEN - 1] &&
		(STACK[0] > O_STACK[O_LEN - 1] || STACK[0] < O_STACK[0]))))
		{
			display_array(data->a, "a afer rot");
			display_array(data->b, "b afer rot");
			O_ROTATE;
		}
		PUSH;
		len--;
	}
}
