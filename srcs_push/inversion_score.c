/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inversion_score.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 10:15:52 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/05 10:15:53 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int cmp(int a, int b, char stck)
{
	if (stck == 'a')
		return (a < b);
	else if (stck == 'b')
		return (a > b);
	else
		ft_error("Wtf, what stack did you give to cmp?");
	return (-1);
}

int			ordered(int *st, int len, char stck)
{
	int i;
	int bad_count;

	bad_count = 0;
	i = 0;
	while (i < len)
	{
		if (!cmp(st[i], st[(i + 1) % len], stck))
			bad_count++;
		if (bad_count >= 2)
			return (0);
	}
	return (1);
}

int			inversion_score(int *st, int len, char stck)
{
	int i;
	int j;
	int inver;

	inver = 0;
	i = 1;
	while (i == 1 || i < (len - 1) / 2)
	{
		j = 0;
		while (j < len)
		{
			if (!cmp(st[j], st[(j + i) % len], stck))
				inver += 2;
			j++;
		}
		inver -= 2 * i;
		i++;
	}
	return (inver);
}
