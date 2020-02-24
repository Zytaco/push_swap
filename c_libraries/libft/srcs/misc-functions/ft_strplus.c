/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strplus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 14:21:05 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/20 14:21:05 by jheeresm      ########   odam.nl         */
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

void	ft_strminus(char **s, int s_base, ULL x, size_t i)
{
	int val;

	if (*s && **s == '-')
	{
		
	}
}

void	ft_strplus(char **s, int s_base, ULL x, size_t i)
{
	int val;

	if (!s[0])
		s[0] = ft_strdup("0");
	while (x > 0)
	{
		if (i < 0 || !ft_isdigit(s[0][i]))
			ft_strins(s, "0", ft_max(i, 0));
		val = to_value(s[0][i] + (x % s_base));
		x /= s_base;
		if (val >= s_base)
		{
			x += val / s_base;
			val = val % s_base;
		}
		s[0][i] = from_value(val);
		i--;
	}
}
