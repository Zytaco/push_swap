/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_num.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:14:57 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/08 13:14:58 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_printf_num(t_flags *flags, va_list list)
{
	int		*n;

	n = va_arg(list, int*);
	*n = *(flags->count);
	return (NULL);
}
