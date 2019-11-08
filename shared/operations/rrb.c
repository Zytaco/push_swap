/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrb.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:55:12 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:55:13 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		rrb(t_data *data)
{
	int i;
	int temp;

	if (data->b->size <= 0)
		return ;
	temp = data->b->array[data->b->size - 1];
	i = 0;
	while (i + 1 < data->b->size)
	{
		data->b->array[i + 1] = data->b->array[i];
		i++;
	}
	data->b->array[0];
	add_operation(data, "rrb\n");
}
