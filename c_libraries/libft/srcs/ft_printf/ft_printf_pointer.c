/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_pointer.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:42:36 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/17 12:42:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_point_flag_cor(t_flags *f)
{
	f->hash = 1;
	if (f->smallest + f->small + f->big + f->biggest > 1)
		ft_error("ERROR: ft_printf: multiple size flags are active on a %s.");
	if (f->minus && f->zero)
		f->zero = 0;
}

char		*ft_printf_pointer(t_flags *flags, va_list list)
{
	char *arg;

	ft_printf_point_flag_cor(flags);
	arg = ft_utobase(va_arg(list, unsigned int), 16);
	return (arg);
}
