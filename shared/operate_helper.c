/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operate_helper.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 14:48:54 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/22 14:48:55 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "operate.h"

static void	reverse_rotate(t_tack *stk)
{
	int temp;
	int i;

	temp = stk->stack[stk->length - 1];
	i = stk->length - 2;
	while (i >= 0)
	{
		stk->stack[i + 1] = stk->stack[i];
		i--;
	}
	stk->stack[0] = temp;
}

void		operate_helper(char *line, int i, t_tack *a, t_tack *b)
{
	if ((i == -1 && ft_strcmp(line, "rra") == 0) || i == 8)
		reverse_rotate(a);
	else if ((i == -1 && ft_strcmp(line, "rrb") == 0) || i == 9)
		reverse_rotate(b);
	else if ((i == -1 && ft_strcmp(line, "rrr") == 0) || i == 10)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}
