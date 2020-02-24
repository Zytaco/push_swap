/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:11:59 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/11 14:12:00 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

LL	ft_max(LL a, LL b)
{
	if (a >= b)
		return (a);
	return (b);
}
