/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:54:15 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:54:15 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sb(t_data *data)
{
	int temp;

	if (data->b->size < 2)
		return ;
	temp = data->b->array[0];
	data->b->array[0] = data->b->array[1];
	data->b->array[1] = temp;
	add_operation(data, "sb\n");
}
