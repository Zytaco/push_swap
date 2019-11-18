/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:23 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:23 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				sa(t_data *data, int bool)
{
	int temp;

	if (data->a.len <= 1)
		return ;
	temp = data->a.stack[0];
	data->a.stack[0] = data->a.stack[1];
	data->a.stack[1] = temp;
	if (bool)
		add_operation(data, "sa\n");
}
