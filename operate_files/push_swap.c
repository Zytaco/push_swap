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

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

/*
** NOTE: use ARG = (4 67 3) instead of ARG = "4 67 3" so tit's not a string
** but multiple arguments
*/

static void	write_solution(char **solution)
{
	int i;

	if (*solution == NULL)
	{
		write(1, "Error\n", 6);
		return ;
	}
	i = 0;
	while ((*solution)[i])
		i++;
	while (i > 0)
	{
		i--;
		write(1, *solution + i, 1);
	}
	free(*solution);
	*solution = NULL;
}

/*
** action	i		inverse		i
** sa		0		sa			0
** sb		1		sb			1
** ss		2		ss			2
** pa		3		pb			4
** pb		4		pa			3
** ra		5		rra			8
** rb		6		rrb			9
** rr		7		rrr			10
** rra		8		ra			5
** rrb		9		rb			6
** rrr		10		rr			7
*/

static void	undo_operation(t_tack *a, t_tack *b, int i, int ret)
{
	if (0 <= i && i <= 2)
		operate(NULL, i, a, b);
	else if (i == 3 && ret == 1)
		operate(NULL, 4, a, b);
	else if (i == 4 && ret == 1)
		operate(NULL, 3, a, b);
	else if (5 <= i && i <= 7)
		operate(NULL, i + 3, a, b);
	else if (8 <= i && i <= 10)
		operate(NULL, i - 3, a, b);
}

/*
** level starts at 0 and solver only checks.
** then it's 1 and solver checks, does one level of operations
*/
/*
** sa	switch top elements of a
** sb	switch top elements of b
** ss	sa and sb
** pa	move top of b to top of a
** pb	move top of b to top of a
** ra	first of a becomes last and other elements shift
** rb	first of b becomes last and other elements shift
** rr	ra and rb
** rra	last of a becomes first and other elements shift
** rrb	last of b becomes first and other elements shift
** rrr	rra and rrb
*/
/*
** add_operation adds the commands reversed because things are added in reverse
** that way when the solution is read in reverse things come out correctly.
*/

static char	*add_operation(char **solution, int i, char *temp)
{
	if (i == 0)
		temp = ft_strjoin(*solution, "\nas");
	else if (i == 1)
		temp = ft_strjoin(*solution, "\nbs");
	else if (i == 2)
		temp = ft_strjoin(*solution, "\nss");
	else if (i == 3)
		temp = ft_strjoin(*solution, "\nap");
	else if (i == 4)
		temp = ft_strjoin(*solution, "\nbp");
	else if (i == 5)
		temp = ft_strjoin(*solution, "\nar");
	else if (i == 6)
		temp = ft_strjoin(*solution, "\nbr");
	else if (i == 7)
		temp = ft_strjoin(*solution, "\nrr");
	else if (i == 8)
		temp = ft_strjoin(*solution, "\narr");
	else if (i == 9)
		temp = ft_strjoin(*solution, "\nbrr");
	else if (i == 10)
		temp = ft_strjoin(*solution, "\nrrr");
	free(*solution);
	*solution = NULL;
	return (temp);
}

static int	solver(t_tack a, t_tack b, char **solution, int level)
{
	int		i;
	char	*temp;
	int		ret;

	if (level <= 0 && check_stacks(a, b) == 1)
		return (1);
	if (level > 0)
	{
		i = 0;
		while (i < 11)
		{
			ret = operate(NULL, i, &a, &b);
			if (solver(a, b, solution, level - 1) == 1)
			{
				temp = NULL;
				if (*solution != NULL)
					*solution = add_operation(solution, i, temp);
				return (1);
			}
			undo_operation(&a, &b, i, ret);
			i++;
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_tack	a;
	t_tack	b;
	char	*solution;
	int		level;

	if (argc <= 1)
		return (1);
	solution = ft_strnew(0);
	if (solution == NULL || make_stack(argc, argv, &a, &b) == 0 ||
	check_duplicates(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	level = 0;
	while (solver(a, b, &solution, level) == 0)
		level++;
	write_solution(&solution);
	free(a.stack);
	free(b.stack);
	return (1);
}
