/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sb.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:28 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:28 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				sb(t_data data, int bool)
{
	int temp;

	if (data.b->len <= 1)
		return ;
	temp = data.b->stack[0];
	data.b->stack[0] = data.b->stack[1];
	data.b->stack[1] = temp;
	if (bool)
		add_operation(data, "sb\n");
}
