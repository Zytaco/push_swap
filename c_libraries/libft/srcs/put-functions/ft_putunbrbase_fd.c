/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunbrbase_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 10:20:08 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/09 10:20:08 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** maximum length: 64
** 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111
*/

void			ft_putunbrbase_fd(ULL n, int base, int fd)
{
	const char	upper[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char		s[65];
	int			i;

	if (base < 2 || base > 36)
		return ;
	if (n == 0)
		write(fd, "0", 1);
	else
	{
		s[64] = '\0';
		i = 64;
		while (n > 0)
		{
			i--;
			s[i] = upper[n % base];
			n /= base;
		}
		ft_putstr_fd(s + i, fd);
	}
}
