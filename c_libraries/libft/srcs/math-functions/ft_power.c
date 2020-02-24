/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_power.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/06 16:06:30 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/06 16:06:38 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

LL	ft_power(int num, int power)
{
	LL x;

	x = num;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		x *= x;
		power--;
	}
	return (x);
}
