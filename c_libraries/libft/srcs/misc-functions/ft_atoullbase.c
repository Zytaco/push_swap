/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoullbase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 10:06:01 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/07 10:06:01 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		get_index(const char *str, const char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c || ft_tolower(str[i]) == c)
		return (i);
	else
		return (-1);
}

ULL		ft_atoullbase(const char *s, int base)
{
	const char	uppercase[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	ULL			x;
	int			i;

	if (base <= 0 || base > 36)
		return (0ULL);
	else if (base == 1)
		return (ft_strlen(s));
	x = 0;
	while (s[0])
	{
		i = get_index(uppercase, s[0]);
		if (i < 0)
			break ;
		else
			x = (x * base) + i;
		s++;
	}
	return (x);
}
