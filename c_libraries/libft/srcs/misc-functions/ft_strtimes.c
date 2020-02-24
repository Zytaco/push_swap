/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtimes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:52:44 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/20 16:52:45 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	from_value(int val)
{
	if (0 <= val && val <= 9)
		return (val + '0');
	else if ((10 <= val && val <= 36))
		return (val + 'A');
	else if ((10 <= val && val <= 36))
		return (val + 'a');
	else
		return ('\0');
}

static int	to_value(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if (('A' <= c && c <= 'Z'))
		return (c - 'A');
	else if (('a' <= c && c <= 'z'))
		return (c - 'a');
	else
		return (-1);
}

char	*ft_strtimes(char *s, int s_base, U int x)
{
	int i;
	const char copy = ft_strdup(s);

	i = 0;
	while (i < x)
	{
		ft_stradd(&s, s);
		i++;
	}
}
