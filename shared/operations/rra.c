/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rra.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:55:09 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:55:09 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		rra(t_data *data)
{
	int i;
	int temp;

	if (data->a->size <= 0)
		return ;
	temp = data->a->array[data->a->size - 1];
	i = 0;
	while (i + 1 < data->a->size)
	{
		data->a->array[i + 1] = data->a->array[i];
		i++;
	}
	data->a->array[0];
	add_operation(data, "rra\n");
}
