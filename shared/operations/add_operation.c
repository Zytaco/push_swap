/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_operation.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 14:30:13 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 14:30:13 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	add_operation(t_data *data, char *op)
{
	char *temp;

	temp = data->sol->solution;
	data->sol->solution = ft_strjoin(data->sol->solution, op);
	free(temp);
}
