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

void				pb(t_data *data)
{
	if (data->a->len <= 0)
		return ;
	data->b->len++;
	rrb(data);
	data->b->stack[0] = data->a->stack[0];
	ra(data);
	data->a->len--;
}
