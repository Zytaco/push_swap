/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_make.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:15:26 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/25 14:15:26 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "check_and_make.h"

static int	check_if_int(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while ('0' <= s[i] && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return (1);
	else
		return (0);
}

int			check_stacks(t_tack stk_one, t_tack stk_two)
{
	int i;

	if (stk_two.length != 0)
		return (0);
	i = 0;
	while (i < stk_one.length - 1)
	{
		if (stk_one.stack[i] >= stk_one.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			make_stack(int argc, char **argv, t_tack *stk_one, t_tack *stk_two)
{
	int i;

	stk_two->length = 0;
	stk_two->stack = (int*)malloc(sizeof(int) * (argc - 1));
	stk_one->stack = (int*)malloc(sizeof(int) * (argc - 1));
	if (stk_one->stack == (int*)0 && stk_two->stack == (int*)0)
		return (-1);
	stk_one->length = argc - 1;
	i = 1;
	while (i < argc)
	{
		if (check_if_int(argv[i]) == 0)
			return (0);
		stk_one->stack[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}
