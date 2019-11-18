/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:42 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:42 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				pb(t_data *data, int bool)
{
	if (data->a.len <= 0)
		return ;
	data->b.len++;
	rrb(data, 0);
	data->b.stack[0] = data->a.stack[0];
	ra(data, 0);
	data->a.len--;
	if (bool)
		add_operation(data, "pb\n");
}
