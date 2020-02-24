/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcut.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:41:49 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/10 12:41:49 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** 1234567
** len		7
** start	1
** end		2
*/

char	*ft_strcut(char **s, size_t start, size_t end)
{
	const size_t	len = ft_strlen(s);
	char			*new;

	if (!s || !*s)
		return (NULL);
	if (start >= len || end >= len || start >= end)
		return (*s);
	new = ft_strnew(len - end + start);
	if (!new)
		return (NULL);
	ft_strncpy(new, *s, start);
	ft_strncpy(new, *s + end, len - end);
	*s = new;
	return (new);
}
