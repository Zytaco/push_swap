/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 13:44:12 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:23:38 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i < len)
	{
		if (src[i - j] != 0)
			dst[i] = src[i];
		else
		{
			dst[i] = '\0';
			j++;
		}
		i++;
	}
	return (dst);
}
