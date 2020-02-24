/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 13:37:57 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:52:32 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	char	*ptr2;
	size_t	i;

	if (size <= 0)
		return (NULL);
	ptr = (void*)malloc(size);
	if (ptr == NULL)
		ft_error("malloc failed");
	ptr2 = ptr;
	i = 0;
	while (i < size)
	{
		ptr2[i] = 0;
		i++;
	}
	return (ptr);
}
