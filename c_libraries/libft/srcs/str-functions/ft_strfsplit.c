/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strfsplit.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 16:02:42 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/11 16:02:42 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t		malloc_size(char const *s, int (*split)(int))
{
	size_t i;
	size_t splits;

	if (!s)
		return (0);
	splits = 0;
	i = 0;
	while (s[i])
	{
		if (!split(s[i]) && (!s[i + 1] || split(s[i + 1])))
			splits++;
		i++;
	}
	return (sizeof(char*) * (splits + 1));
}

char				**ft_strfsplit(char const *s, int (*split)(int))
{
	char	**const array = ft_memalloc(malloc_size(s, split));
	size_t	i;
	size_t	start;
	size_t	end;

	if (s == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (s[start] && split(s[start]))
		start++;
	while (s[start])
	{
		end = start;
		while (s[end] && !split(s[end]))
			end++;
		array[i] = ft_memalloc(sizeof(char) * (end - start + 1));
		ft_strncpy(array[i], s + start, end - start);
		i++;
		start = end;
		while (s[start] && split(s[start]))
			start++;
	}
	return (array);
}
