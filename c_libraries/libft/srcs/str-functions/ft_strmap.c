/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 16:13:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:20:05 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	str = (char*)malloc(sizeof(*s) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	j = 0;
	while (j < i)
	{
		str[j] = f(s[j]);
		j++;
	}
	return (str);
}
