/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ss.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:54:19 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:54:19 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss(t_data *data)
{
	int temp;

	if (data->a->size < 2 || data->b->size < 2)
		return ;
	temp = data->a->array[0];
	data->a->array[0] = data->a->array[1];
	data->a->array[1] = temp;
	temp = data->b->array[0];
	data->b->array[0] = data->b->array[1];
	data->b->array[1] = temp;
	add_operation(data, "ss\n");
}
