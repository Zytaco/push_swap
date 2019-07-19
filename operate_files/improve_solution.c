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

t_word		*get_next(t_word *seed)
{
	t_word *ret;

	ret = NULL;
	if (seed)
		ret = seed->next;
	while (ret && ret->word[0] == '.')
		ret = ret->next;
	return (ret);
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
		two = get_next(one);
		three = get_next(two);
		if ((one && two && two_checks(one->word, two->word)) || (one && two &&
		ss_checks(one->word, two->word)) || (one && two && three &&
		three_checks(one->word, two->word, three->word)))
		{
			if (one->prev)
				one = one->prev;
			if (one->prev)
				one = one->prev;
			while (one->prev && one->word[0] == '.')
				one = one->prev;
		}
		else
			one = one->next;
	}
}
