/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/06 16:04:41 by tide-jon       #+#    #+#                */
/*   Updated: 2019/07/06 16:04:57 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int				ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}
