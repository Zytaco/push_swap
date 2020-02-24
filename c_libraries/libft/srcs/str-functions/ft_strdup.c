/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:13:43 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:15:26 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	size_t	length;
	size_t	i;

	length = 0;
	while (src[length])
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
