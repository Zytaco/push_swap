/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrr.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:55:15 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 17:55:16 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		rrr(t_data *data)
{
	if (data->a->size <= 0 || data->b->size <= 0)
		return ;
	rra(data);
	rrb(data);
	data->solution[ft_strlen(data->solution) - 8] = '\0';
	add_operation(data, "rrr\n");
}
