/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 16:35:59 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:21:32 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

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
		str[j] = f(j, s[j]);
		j++;
	}
	return (str);
}
