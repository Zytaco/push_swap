/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 17:47:46 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/11 17:47:46 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*cpy;
	size_t	length;
	size_t	i;

	length = 0;
	while (src[length] && length + 1 < len)
		length++;
	cpy = (char*)malloc(sizeof(char) * (length + 1));
	if (cpy == (char*)0)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = src[i];
	return (cpy);
}
