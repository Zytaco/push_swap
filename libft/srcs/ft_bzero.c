/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 12:53:28 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 16:34:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n > 1)
	{
		n--;
		str[n] = 0;
	}
}
