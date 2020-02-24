/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skipstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 14:56:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/18 14:56:08 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	in_str(const char c, const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

int			ft_skipstr(const char *str, const char *skip)
{
	int i;

	i = 0;
	if (!str || !skip)
		return (0);
	while (str[i] && in_str(str[i], skip))
		i++;
	return (i);
}

int			ft_skipnstr(const char *str, const char *skip)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && !in_str(str[i], skip))
		i++;
	return (i);
}
