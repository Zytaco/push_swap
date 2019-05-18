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

static void	rotate(int *stk, int len)
{
	int temp;
	int i;

	temp = stk[0];
	i = 0;
	while (i <= len - 2)
	{
		stk[i] = stk[i + 1];
		i++;
	}
	stk[len - 1] = temp;
}

static void	reverse_rotate(int *stk, int len)
{
	int temp;
	int i;

	temp = stk[len - 1];
	i = len - 2;
	while (i >= 0)
	{
		stk[i + 1] = stk[i];
		i--;
	}
	stk[0] = temp;
}

static void	rotation(t_tack a, int i, char **solution)
{
	int *stk;

	stk = a.stack;
	if (i > a.length / 2)
		i -= a.length;
	while (i > 0)
	{
		*solution = ft_strfajoin(solution, "ra.\n");
		rotate(a.stack, a.length);
		i--;
	}
	while (i < 0)
	{
		*solution = ft_strfajoin(solution, "rra\n");
		reverse_rotate(a.stack, a.length);
		i++;
	}
}

void		optimal_rotation(t_tack a, char **solution)
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
	rotation(a, i, solution);
}
