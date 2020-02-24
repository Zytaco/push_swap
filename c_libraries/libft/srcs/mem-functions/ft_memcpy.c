/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:03:01 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:00:56 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tempdst;
	const char	*tempsrc;

	tempdst = (char*)dst;
	tempsrc = (const char*)src;
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			tempdst[i] = tempsrc[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			tempdst[i] = tempsrc[i];
		}
	}
	return (dst);
}
