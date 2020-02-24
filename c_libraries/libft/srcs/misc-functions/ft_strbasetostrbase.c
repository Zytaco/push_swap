/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strbasetostrbase.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/13 16:06:49 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/13 16:06:49 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// static void str_add(char **s, int s_base, size_t i, int val)
// {
// 	int new_val;

// 	if (s[0][0] == '-')
// 		val *= -1;
// 	if (i < 0 || (i == 0 && s[0][1] == '-'))
// 	{
// 		ft_strprep("0", s);
// 		if (s[0][1] == '-')
// 		{
// 			s[0][0] = '-';
// 			s[0][1] = '0';
// 		}
// 		str_add(s, s_base, i + 1, val);
// 		return ;
// 	}
// 	new_val = to_value(s[0][i]) + val;
// 	if (new_val < 0 || new_val + val >= s_base)
// 	{
// 		str_add(s, s_base, i - 1, new_val / s_base);
// 		new_val = ft_modulo(new_val, s_base);
// 	}
// 	s[0][i] = new_val;
// }

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

/*
** 10-base 7 -> 7-base 10
**
*/

char		*ft_strbasetostrbase(const char *in, int in_base, int out_base)
{
	size_t			i;
	char const		*copy = ft_strdup(in + ((*in == '-') ? 1 : 0));
	const size_t	len = ft_strlen(copy);
	char			*out;
	int				val;

	i = 0;
	while (copy[0] != '0')
	{
		
	}
	return ((*in == '-') ? ft_strprep("-", &out) : out);
}
