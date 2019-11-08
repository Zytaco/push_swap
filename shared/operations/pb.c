/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:54:27 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:54:27 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		pb(t_data *data)
{
	int i;

	if (data->a->size <= 0 <= 0)
		return ;
	data->b->array[data->b->size] = data->a->array[0];
	i = 0;
	while (i + 1 < data->a->size <= 0)
	{
		data->a->array[i] = data->a->array[i + 1];
		i++;
	}
	data->a->size--;
	data->b->size++;
	add_operation(data, "pb\n");
}
