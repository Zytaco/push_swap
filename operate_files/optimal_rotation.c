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
#include <stdio.h>

int		find_biggest(int *stk, int len)
{
	int i;
	int biggest;

	if (len <= 0)
		return (-1);
	biggest = stk[0];
	i = 1;
	while (i < len)
	{
		if (stk[i] > biggest)
			biggest = stk[i];
		i++;
	}
	return (biggest);
}

void	rotation_a(t_tack st, int i, t_word *list)
{
	int *stk;

	stk = st.stack;
	if (i > st.length / 2)
		i -= st.length;
	while (i > 0)
	{
		swap_a_maybe(st, list);
		do_thing_a("ra.", list, &st, NULL);
		i--;
	}
	while (i < 0)
	{
		swap_a_maybe(st, list);
		do_thing_a("rra", list, &st, NULL);
		i++;
	}
}

void	rotation_b(t_tack st, int i, t_word *list)
{
	int *stk;

	stk = st.stack;
	if (i > st.length / 2)
		i -= st.length;
	while (i > 0)
	{
		swap_b_maybe(st, list);
		do_thing_b("rb.", list, NULL, &st);
		i--;
	}
	while (i < 0)
	{
		swap_b_maybe(st, list);
		do_thing_b("rrb", list, NULL, &st);
		i++;
	}
}

void	optimal_rotation(t_tack a, t_word *list, char name)
{
	int i;
	int *stk;
	int start;

	if (a.length <= 0)
		return ;
	stk = a.stack;
	i = 0;
	while (stk[i] != 0)
		i++;
	start = i;
	if (a.length > 1 && stk[(i + 1) % a.length] == stk[i % a.length] + 1)
		i++;
	while (stk[(i + 1) % a.length] % a.length ==
	(stk[i % a.length] + 1) % a.length &&
	stk[(i - 1) % a.length] != 0)
		i++;
	i++;
	i %= a.length;
	if (name == 'a')
		rotation_a(a, i, list);
	if (name == 'b')
		rotation_b(a, i, list);
}
