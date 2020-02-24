/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_uint.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 11:19:46 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/09 11:19:47 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printf_uint_flag_cor(t_flags *f)
{
	if (f->smallest + f->small + f->big + f->biggest > 1)
		ft_error("ERROR: ft_printf: multiple size flags are active on a %s.");
	if (f->minus && f->zero)
		f->zero = 0;
}

char			*ft_printf_uint(t_flags *flags, int base, char upper,
																va_list list)
{
	char *arg;

	ft_printf_uint_flag_cor(flags);
	if (flags->smallest)
		arg = ft_utobase((ULL)va_arg(list, unsigned int), base);
	else if (flags->small)
		arg = ft_utobase((ULL)va_arg(list, unsigned int), base);
	else if (flags->big)
		arg = ft_utobase((ULL)va_arg(list, unsigned long), base);
	else if (flags->biggest)
		arg = ft_utobase((ULL)va_arg(list, ULL), base);
	else
		arg = ft_utobase((ULL)va_arg(list, unsigned int), base);
	if (!upper)
		ft_strlower(arg);
	return (arg);
}
