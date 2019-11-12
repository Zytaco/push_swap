/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrb.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:05:04 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:05:04 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				rrb(t_data data, int bool)
{
	int i;
	int temp;
	int *stack;
	int len;

	len = data.b->len;
	if (len <= 1)
		return ;
	stack = data.b->stack;
	temp = stack[len - 1];
	i = len - 2;
	while (i >= 0)
	{
		stack[i + 1] = stack[i];
		i--;
	}
	stack[0] = temp;
	if (bool)
		add_operation(data, "rrb\n");
}
