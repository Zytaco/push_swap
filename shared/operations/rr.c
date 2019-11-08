/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rr.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:54:59 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:55:00 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		rr(t_data *data)
{
	if (data->a->size <= 0 || data->b->size <= 0)
		return ;
	ra(data);
	rb(data);
	data->solution[ft_strlen(data->solution) - 6] = '\0';
	add_operation(data, "rr\n");
}
