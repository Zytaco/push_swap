/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bcd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 12:40:57 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/12 12:40:57 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

LL	ft_bcd(LL a, LL b)
{
	ULL i;
	ULL denom;

	if (a == 0 || b == 0 || (a < 0 && b > 0) || (a > 0 && b < 0))
		return (0);
	i = 1;
	denom = a / i;
	while (i <= denom)
	{
		if (a % denom == 0 && b % denom == 0)
			return (denom);
		i++;
		denom = a / i;
	}
	return (denom);
}
