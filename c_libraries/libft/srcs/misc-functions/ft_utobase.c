/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utobase.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 11:06:28 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/09 11:06:28 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_utobase(ULL n, int base)
{
	const char	uppercase[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char		s[sizeof(ULL) * 8 + 1];
	int			i;

	if (base < 1 || sizeof(ULL) <= 0)
		return (NULL);
	if (base == 1)
		return (ft_strrepeat("0", n));
	if (n == 0)
		return (strdup("0"));
	i = sizeof(ULL) * 8;
	s[i] = '\0';
	while (n > 0 && i > 0)
	{
		i--;
		s[i] = uppercase[n % base];
		n /= base;
	}
	return (ft_strdup(s + i));
}
