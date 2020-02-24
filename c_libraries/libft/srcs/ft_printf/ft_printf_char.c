/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 12:42:22 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/17 12:42:22 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_char_flag_cor(t_flags *f)
{
	if (f->smallest + f->small + f->big + f->biggest > 1)
		ft_error("ERROR: ft_printf: multiple size flags are active on a %s.");
	if (f->minus && f->zero)
		f->zero = 0;
}

char		*ft_printf_char(t_flags *flags, va_list list)
{
	char *arg;

	ft_printf_char_flag_cor(flags);
	arg = ft_strdup((char[2]){(signed char)va_arg(list, int), '\0'});
	return (arg);
}
