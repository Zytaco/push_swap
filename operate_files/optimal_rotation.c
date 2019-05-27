/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimal_rotation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 11:26:34 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/16 11:26:34 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "optimal_rotation.h"
#include <unistd.h>

void	rotation(t_tack a, int i, t_word *list)
{
	int *stk;

	stk = a.stack;
	if (i > a.length / 2)
		i -= a.length;
	while (i > 0)
	{
		new_to_list(list, "ra.");
		rotate(a.stack, a.length);
		i--;
	}
	while (i < 0)
	{
		new_to_list(list, "rra");
		reverse_rotate(a.stack, a.length);
		i++;
	}
}

void		optimal_rotation(t_tack a, t_word *list)
{
	int i;
	int *stk;
	int start;

	stk = a.stack;
	i = 0;
	start = -1;
	while (start == -1)
	{
		if (stk[i] == 0)
			start = i;
		i++;
	}
	i--;
	if (stk[(i + 1) % a.length] == stk[i % a.length] + 1)
		i++;
	while (stk[(i + 1) % a.length] % a.length ==
	(stk[i % a.length] + 1) % a.length &&
	i % a.length != start)
		i++;
	i++;
	i %= a.length;
	rotation(a, i, list);
}
