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
#include <unistd.h>
#include "check_and_make.h"

int			check_duplicates(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i + 1 <= argc - 1)
	{
		j = i + 1;
		while (j <= argc - 1)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

int			check_stacks(t_tack a, t_tack b)
{
	int i;

	if (b.length > 0)
		return (0);
	i = 0;
	while (i < a.length - 1)
	{
		if (a.stack[i] >= a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			make_stack(int argc, char **argv, t_tack *a, t_tack *b)
{
	int i;

	b->length = 0;
	b->stack = (int*)malloc(sizeof(int) * (argc - 1));
	a->stack = (int*)malloc(sizeof(int) * (argc - 1));
	if (a->stack == (int*)0 && a->stack == (int*)0)
		return (-1);
	a->length = argc - 1;
	i = 1;
	while (i < argc)
	{
		if (check_if_int(argv[i]) == 0)
			return (0);
		a->stack[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}
