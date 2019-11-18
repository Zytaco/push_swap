/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ss.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 13:04:31 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 13:04:31 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void				ss(t_data *data, int bool)
{
	sa(data, 0);
	sb(data, 0);
	if (bool)
		add_operation(data, "ss\n");
}
