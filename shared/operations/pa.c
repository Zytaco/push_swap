/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:54:23 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:54:24 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		pa(t_data *data)
{
	int i;

	if (data->b->size <= 0)
		return ;
	data->a->array[data->a->size] = data->b->array[0];
	i = 0;
	while (i + 1 < data->b->size <= 0)
	{
		data->b->array[i] = data->b->array[i + 1];
		i++;
	}
	data->a->size++;
	data->b->size--;
	add_operation(data, "pa\n");
}
