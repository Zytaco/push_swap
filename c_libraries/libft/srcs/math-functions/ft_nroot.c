/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nroot.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/31 18:04:56 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/10/31 18:04:56 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int				ft_nroot(unsigned int num, unsigned int degree)
{
	unsigned int res;

	res = 0;
	while (ft_power(num, degree) < num)
		res++;
	return (res);
}
