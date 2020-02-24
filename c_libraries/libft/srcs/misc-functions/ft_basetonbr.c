/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_basetobase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:55:10 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/10 13:55:10 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_atoi(const char *str)
{
	int sign;
	int value;

	sign = 1;
	value = 0;
	while (ft_iswhitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		value = 10 * value + sign * (*str - '0');
		str++;
	}
	return (value);
}

LL		ft_basetonbr(const char *s, int base)
{
	int	sign;
	LL	value;

	sign = 1;
	value = 0;
	if (base < 2 || base > 36)
		return (0);
	while (ft_iswhitespace(*s))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s) || ('A' < ft_toupper(*s) && ft_toupper(*s) < 'Z'))
	{
		value *= base;
		if (ft_isdigit(*s))
			value += sign * (*s - '0');
		else if ('A' < *s && *s < 'Z')
			value += sign * (*s - 'A' + 10);
		else
			value += sign * (*s - 'a' + 10);
		s++;
	}
	return (value);
}
