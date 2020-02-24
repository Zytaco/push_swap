/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrepeat.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 16:37:50 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/11 16:37:50 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrepeat(const char *s, ULL n)
{
	char		*new;
	ULL			i;
	ULL			j;
	const ULL	len = ft_strlen(s);

	if (!s || n <= 0)
		return (NULL);
	new = ft_strnew(n * len);
	if (!new)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		j = 0;
		while (j < len)
		{
			new[i + j] = s[j];
			j++;
		}
		i += j;
		n--;
	}
	return (new);
}
