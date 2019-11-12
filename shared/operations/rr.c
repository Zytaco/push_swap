/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rr.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:54 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:55 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				rr(t_data data, int bool)
{
	ra(data, 0);
	rb(data, 0);
	if (bool)
		add_operation(data, "rr\n");
}
