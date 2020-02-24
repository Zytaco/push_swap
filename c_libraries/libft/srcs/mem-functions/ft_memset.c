/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:52:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:05:11 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*array;
	unsigned char	temp;
	size_t			i;

	i = 0;
	temp = (unsigned char)c;
	array = (unsigned char*)b;
	while (i < len)
	{
		*(array + i) = temp;
		i++;
	}
	return (b);
}
