/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:54:31 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:54:31 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		ra(t_data *data)
{
	int i;
	int temp;

	if (data->a->size <= 0)
		return ;
	temp = data->a->array[0];
	i = 0;
	while (i + 1 < data->a->size)
	{
		data->a->array[i] = data->a->array[i + 1];
		i++;
	}
	data->a->array[data->a->size - 1];
	add_operation(data, "ra\n");
}
