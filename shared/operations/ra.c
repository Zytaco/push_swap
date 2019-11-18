/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:47 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:47 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ra(t_data *data, int bool)
{
	int i;
	int temp;
	int *stack;
	int len;

	len = data->a.len;
	if (len <= 1)
		return ;
	stack = data->a.stack;
	temp = stack[0];
	i = 0;
	while (i + 1 < len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = temp;
	if (bool)
		add_operation(data, "ra\n");
}
