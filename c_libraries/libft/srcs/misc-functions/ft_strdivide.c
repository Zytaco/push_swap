/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdivide.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:17:31 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/20 16:17:31 by jheeresm      ########   odam.nl         */
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

char	*ft_strdivide(char *s, int s_base, U int x)
{
	char	*out;
	size_t	i;
	U int	carry;

	if (x == 0 || x == 1)
		return (s);
	carry = 0;
	i = 0;
	while (s[i])
	{
		carry *= s_base;
		carry += to_value(s[i]);
		s[i] = from_value((int)(carry / x));
		carry %= x;
		i++;
	}
	return (s);
}
