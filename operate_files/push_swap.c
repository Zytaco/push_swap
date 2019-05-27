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

#include "push_swap.h"
#include <stdio.h>

/*
** NOTE: use ARG = (4 67 3) instead of ARG = "4 67 3" so tit's not a string
** but multiple arguments
*/

static void	print_list(t_word *start)
{
	while (start != NULL)
	{
		if (start->word[0] != '.')
			write(1, start->word, 1);
		if (start->word[1] != '.')
			write(1, start->word + 1, 1);
		if (start->word[2] != '.')
			write(1, start->word + 2, 1);
		if (start->word[0] != '.' ||
		start->word[1] != '.' ||
		start->word[2] != '.')
			write(1, "\n", 1);
		if (start->next == NULL)
		{
			free(start);
			return ;
		}
		else
		{
			start = start->next;
			free(start->prev);
		}
	}
}

int			main(int argc, char **argv)
{
	t_tack	a;
	t_tack	b;
	t_word	*start;

	start = make_word("...");
	if (argc <= 1)
		return (1);
	if (make_stack(argc, argv, &a, &b) != 1 ||
	check_duplicates(argc, argv) != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	simplify_stack(&a);
	solver(a, b, start);
	if (start != NULL)
	{
		while (start->prev != NULL)
			start = start->prev;
		improve_solution(start);
		print_list(start);
	}
	free(a.stack);
	free(b.stack);
	return (1);
}
