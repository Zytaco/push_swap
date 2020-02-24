/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:42:42 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/17 12:42:42 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_int_flag_cor(t_flags *f)
{
	if (f->smallest + f->small + f->big + f->biggest > 1)
		ft_error("ERROR: ft_printf: multiple size flags are active on a %s.");
	if (f->minus && f->zero)
		f->zero = 0;
}

char		*ft_printf_int(t_flags *flags, int base, char upper, va_list list)
{
	char *arg;

	ft_printf_int_flag_cor(flags);
	if (flags->smallest)
		arg = ft_itobase((char)va_arg(list, int), base);
	else if (flags->small)
		arg = ft_itobase((short)va_arg(list, int), base);
	else if (flags->big)
		arg = ft_itobase(va_arg(list, long), base);
	else if (flags->biggest)
		arg = ft_itobase(va_arg(list, long long), base);
	else
		arg = ft_itobase(va_arg(list, signed int), base);
	if (!upper)
		ft_strlower(arg);
	return (arg);
}
