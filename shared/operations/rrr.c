/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrr.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:05:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:05:07 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				rrr(t_data *data, int bool)
{
	rra(data, 0);
	rra(data, 0);
	if (bool)
		add_operation(data, "rrr\n");
}
