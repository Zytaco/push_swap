/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 17:43:56 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/08 11:16:36 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			ft_putnbr_fd(LL n, int fd)
{
	if (n == -9223372036854775807LL)
		ft_putstr("-9223372036854775807");
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putunbr_fd(-1 * n, fd);
	}
	else
		ft_putunbr_fd(n, fd);
}
