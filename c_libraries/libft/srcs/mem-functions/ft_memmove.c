/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:03:01 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:04:34 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tempdst;
	const char	*tempsrc;

	tempdst = (char*)dst;
	tempsrc = (const char*)src;
	if (dst >= src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			tempdst[i] = tempsrc[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			tempdst[i] = tempsrc[i];
			i++;
		}
	}
	return (dst);
}
