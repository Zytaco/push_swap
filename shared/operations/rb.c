/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:54:56 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:54:56 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		rb(t_data *data)
{
	int i;
	int temp;

	if (data->b->size <= 0)
		return ;
	temp = data->b->array[0];
	i = 0;
	while (i + 1 < data->b->size)
	{
		data->b->array[i] = data->b->array[i + 1];
		i++;
	}
	data->b->array[data->b->size - 1];
	add_operation(data, "rb\n");
}
