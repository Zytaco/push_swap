/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:39 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:39 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				pa(t_data *data)
{
	if (data->b->len <= 0)
		return ;
	data->a->len++;
	rra(data);
	data->a->stack[0] = data->b->stack[0];
	rb(data);
	data->b->len--;
}
