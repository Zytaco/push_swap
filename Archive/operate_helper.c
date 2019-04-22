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

#include "checker.h"

static void	reverse_rotate(struct s_tack stk)
{
	int temp;
	int i;

	temp = stk.stack[stk.length - 1];
	i = 0;
	while (i < stk.length - 1)
	{
		stk.stack[i] = stk.stack[i + 1];
		i++;
	}
	stk.stack[0] = temp;
}

void		operate_helper(char *line, struct s_tack a, struct s_tack b)
{
	if (ft_strcmp(line, "rra") == 0)
		reverse_rotate(a);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_rotate(b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		write(1, "ERROR1\n", 7);
}
