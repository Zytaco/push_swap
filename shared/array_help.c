/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   array_help.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 14:13:39 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 14:13:39 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_t_array(t_array *a)
{
	if (!a)
		return ;
	free(a->stack);
	free(a);
}

t_array	*new_array(int len)
{
	t_array *new;

	if (len < 0)
		ft_error("ERROR: new_array() called with len <= 0");
	new = malloc(sizeof(t_array));
	if (!new)
		ft_error("ERROR: malloc failed (new_array)");
	new->stack = malloc(sizeof(int) * len);
	if (!new->stack)
		ft_error("ERROR: malloc failed (new_array)");
	new->len = len;
	return (new);
}

int		get_pos(t_array a, int x)
{
	int i;

	if (!a.stack)
		ft_error("ERROR: get_pos() called without array");
	i = 0;
	while (i < a.len)
	{
		if (a.stack[i] == x)
			return (i);
		i++;
	}
	return (-1);
}
