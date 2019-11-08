/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:53:46 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:53:46 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_data *data)
{
	int temp;

	if (data->a->size < 2)
		return ;
	temp = data->a->array[0];
	data->a->array[0] = data->a->array[1];
	data->a->array[1] = temp;
	add_operation(data, "sa\n");
}
