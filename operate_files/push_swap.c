/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:54:20 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/25 13:54:20 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

/*
** NOTE: use ARG = (4 67 3) instead of ARG = "4 67 3" so tit's not a string
** but multiple arguments
*/
/*
static int	two_checks(char *s, int i, int j)
{
	if ((ft_strncmp(s + i, "pb.\n", 4) && ft_strncmp(s + i + j, "pa.\n", 4))
	|| (ft_strncmp(s + i, "pa.\n", 4) && ft_strncmp(s + i + j, "pb.\n", 4)) ||
	(ft_strncmp(s + i, "sa.\n", 4) && ft_strncmp(s + i + j, "sb.\n", 4)) ||
	(ft_strncmp(s + i, "sb.\n", 4) && ft_strncmp(s + i + j, "sa.\n", 4)) ||
	(ft_strncmp(s + i, "ra\n", 4) && ft_strncmp(s + i + j, "rra\n", 4)) ||
	(ft_strncmp(s + i, "rb\n", 4) && ft_strncmp(s + i + j, "rrb\n", 4)) ||
	(ft_strncmp(s + i, "rra\n", 4) && ft_strncmp(s + i + j, "ra\n", 4)) ||
	(ft_strncmp(s + i, "rrb\n", 4) && ft_strncmp(s + i + j, "rb\n", 4)))
	{
		ft_strcpy(s + i, "....");
		ft_strcpy(s + i + j, "....");
		return (1);
	}
	return (0);
}

static int	three_checks(char *s, int i, int j)
{
	if ((ft_strncmp(s + i, "pb.\n", 4) && ft_strncmp(s + i + j, "ra.\n", 4) &&
	ft_strncmp(s + i + j + 4, "pa.\n", 4)))
	{
		ft_strcpy(s + i, "....");
		ft_strcpy(s + i + j, "sa.\n");
		ft_strcpy(s + i + j + 4, "ra.\n");
		return (1);
	}
	if ((ft_strncmp(s + i, "pb.\n", 4) && ft_strncmp(s + i + j, "rra.\n", 4) &&
	ft_strncmp(s + i + j + 4, "pa.\n", 4)))
	{
		ft_strcpy(s + i, "....");
		ft_strcpy(s + i + j, "rra\n");
		ft_strcpy(s + i + j + 4, "sa.\n");
		return (1);
	}
	return (0);
}

static void	improve_solution(char *s)
{
	int i;
	int j;

	i = 0;
	j = 4;
	while (s[i])
	{
		j = i + 4
		while (s[j] == '.')
			j++;
		if (j <= i)
		{
			j++;
			while (s[j - 1] != '\n')
				j++;
		}
		if (two_checks(s, i, j) || three_checks(s, i, j))
			i -= 4;
		else
			i += 4;
		if (i < 0)
			i = 0;
	}
}
*/

static void	write_solution(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '.')
			write(1, s + i, 1);
		i++;
	}
	free(s);
}

int			main(int argc, char **argv)
{
	t_tack	a;
	t_tack	b;
	char	*solution;

	if (argc <= 1)
		return (1);
	solution = ft_strnew(0);
	solution[0] = '\0';
	if (solution == NULL || make_stack(argc, argv, &a, &b) != 1 ||
	check_duplicates(argc, argv) != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	simplify_stack(&a);
	solver(a, b, &solution);
	// improve_solution(solution);
	write_solution(solution);
	return (1);
}
