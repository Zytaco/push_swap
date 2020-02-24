/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_float.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 13:09:31 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/08 13:09:31 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	mantissa: 8 Bytes
**	determinant: 2 Bytes (-1 bit for sign)
*/

char		*float_exceptions(long double f)
{
	union u_float	u_f;

	u_f.f = f;
	if ((u_f.eld[8] == 255) && (u_f.eld[9] & 127) == 127)
	{
		if (((u_f.eld[7] >> 7) & 1) == 1 && ((u_f.eld[7] >> 6) & 1) == 0 &&
		u_f.eld[6] == 0 && u_f.eld[5] == 0 && u_f.eld[4] == 0 &&
		u_f.eld[3] == 0 && u_f.eld[2] == 0 && u_f.eld[1] == 0 &&
		u_f.eld[0] == 0)
		{
			if ((u_f.eld[9] >> 7) == 1)
				return (ft_strdup("-inf"));
			else
				return (ft_strdup("inf"));
		}
		else
			return (ft_strdup("nan"));
	}
	else
		return (NULL);
}

size_t		get_double_len(long double f, int base)
{
	size_t			len;
	union u_float	u_float;

	u_float.f = f;
	len = 1;
	while (!(-1 * base < f && f < base))
	{
		len++;
		f /= base;
	}
	return ((f < 0) ? len + 1 : len);
}

char		*get_f(long double f, size_t prec, int base)
{
	char			*ret;
	char			bin[82];
	union u_float	u_f;
	int				i;

	ret = float_exceptions(f);
	if (ret)
		return (ret);
	base -= prec;
	u_f.f = f;
	i = 0;
	while (i < 80)
	{
		bin[i] = '0' + ((u_f.eld[i / 8] >> (i % 8)) & 1);
		i++;
	}
	bin[i] = '\0';
	ret = ft_strdup(bin);
	return (ret);
}

static void	ft_printf_float_flag_cor(t_flags *f)
{
	if (!(f->prec_f))
	{
		if (f->type == 'f' || f->type == 'F')
			f->prec = 6;
		else
			ft_error("ERROR: float called with invalid type");
	}
	if ((f->type == 'g' || f->type == 'G') && f->prec_f && f->prec == 0)
		f->prec = 1;
	if (f->smallest + f->small + f->big + f->biggest > 1)
		ft_error("ERROR: ft_printf: multiple size flags are active on a %s.");
	if (f->minus && f->zero)
		f->zero = 0;
}

char		*ft_printf_float(t_flags *flags, va_list list)
{
	char		*arg;

	ft_printf_float_flag_cor(flags);
	if (flags->float_biggest)
		arg = get_f(va_arg(list, long double), flags->prec, 10);
	else
		arg = get_f(va_arg(list, double), flags->prec, 10);
	if (flags->type == ft_toupper(flags->type))
		ft_strupper(arg);
	return (arg);
}
