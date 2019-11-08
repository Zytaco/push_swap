/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_operation.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 18:01:23 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 18:01:23 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_operation(t_data *data, char *op)
{
	char *temp;

	temp = data->solution;
	ft_strjoin(data->solution, op);
	ft_strdel(&temp);
}
