/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   word_helper.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 11:22:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/22 11:22:51 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "word_helper.h"
#include <stdio.h>
#include <unistd.h>

t_word	*make_word(char s[3])
{
	t_word *new;

	new = (t_word*)malloc(sizeof(t_word));
	new->word[0] = s[0];
	new->word[1] = s[1];
	new->word[2] = s[2];
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_word	*new_to_list(t_word *start, char s[3])
{
	t_word *new;

	new = NULL;
	while (new == NULL)
		new = (t_word*)malloc(sizeof(t_word));
	new->word[0] = s[0];
	new->word[1] = s[1];
	new->word[2] = s[2];
	new->next = NULL;
	if (start == NULL)
	{
		new->prev = NULL;
		return (new);
	}
	while (start->next != NULL)
		start = start->next;
	start->next = new;
	new->prev = start;
	return (new);
}

static int	two_checks(char a[3], char b[3])
{
	if ((a[0] == 'p' && a[1] == 'b' && b[0] == 'p' && b[1] == 'a')
	|| (a[0] == 'p' && a[1] == 'a' && b[0] == 'p' && b[1] == 'b') ||
	(a[0] == 'r' && a[1] == 'a' &&
	b[0] == 'r' && b[1] == 'r' && b[2] == 'a') ||
	(a[0] == 'r' && a[1] == 'b' &&
	b[0] == 'r' && b[1] == 'r' && b[2] == 'b') ||
	(a[0] == 'r' && a[1] == 'r' && a[2] == 'a' &&
	b[0] == 'r' && b[1] == 'a') ||
	(a[0] == 'r' && a[1] == 'r' && a[2] == 'b'
	&& b[0] == 'r' && b[1] == 'b'))
	{
		ft_strncpy(a, "...", 3);
		ft_strncpy(b, "...", 3);
		return (1);
	}
	return (0);
}

static int	three_checks(char a[3], char b[3], char c[3])
{
	if (a[0] == 'p' && a[1] == 'b' && b[0] == 'r' &&
	b[1] == 'a' && c[0] == 'p' && c[1] == 'a')
	{
		ft_strncpy(a, "...", 3);
		ft_strncpy(b, "sa.", 3);
		ft_strncpy(c, "ra.", 3);
	}
	else if (a[0] == 'p' && a[1] == 'b' && b[0] == 'r' && b[1] == 'r' &&
	b[2] == 'a' && c[0] == 'p' && c[1] == 'a')
	{
		ft_strncpy(a, "...", 3);
		ft_strncpy(b, "rra", 3);
		ft_strncpy(c, "sa.", 3);
	}
	else if (a[0] == 's' && a[1] == 'a' &&
	b[0] == 'r' && b[1] == 'a' &&
	c[0] == 'p' && c[1] == 'b')
	{
		ft_strncpy(a, "...", 3);
		ft_strncpy(b, "pb.", 3);
		ft_strncpy(c, "ra.", 3);
	}
	else
		return (0);
	return (1);
}

static int	ss_checks(char a[3], char b[3])
{
	if ((a[0] == 's' && a[1] == 'a' &&
	b[0] == 's' && b[1] == 'b') ||
	(a[0] == 'a' && a[1] == 'b' &&
	b[0] == 's' && b[1] == 'a'))
	{
		ft_strncpy(a, "...", 3);
		ft_strncpy(b, "ss.", 3);
		return (1);
	}
	return (0);
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
		if (one)
			two = one->next;
		while (one && two && two->word[0] == '.')
			two = two->next;
		three = NULL;
		if (two != NULL)
			three = two->next;
		while (three && three->word[0] == '.')
			three = three->next;
		if ((one && two && two_checks(one->word, two->word)) ||
		(one && two && ss_checks(one->word, two->word)) ||
		(one && two && three && three_checks(one->word, two->word, three->word)))
		{
			if (one->prev)
				one = one->prev;
			while (one->prev && one->word[0] == '.')
				one = one->prev;
		}
		else
			one = one ->next;
	}
}
