/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   improve_solution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:28:47 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/09 12:28:47 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "improve_solution.h"

t_word		*get_three(t_word *one, t_word *two)
{
	t_word *three;

	three = NULL;
	if (two)
		three = two->next;
	while (three && three->word[0] == '.')
		three = three->next;
}

t_word		*get_two(t_word *one)
{
	t_word *two;

	two = NULL;
	if (one)
		two = one->next;
	while (one && two && two->word[0] == '.')
		two = two->next;
	return (two);
}

void		improve_solution(t_word *start)
{
	t_word *one;
	t_word *two;
	t_word *three;

	one = start;
	while (one != NULL)
	{
		while (one->word[0] == '.' && one->next)
			one = one->next;
		two = get_two(one);
		three = get_three(one, two);
		if ((one && two && two_checks(one->word, two->word)) ||
		(one && two && ss_checks(one->word, two->word)) ||
		(one && two && three &&
		three_checks(one->word, two->word, three->word)))
		{
			if (one->prev)
				one = one->prev;
			while (one->prev && one->word[0] == '.')
				one = one->prev;
		}
		else
			one = one->next;
	}
}
