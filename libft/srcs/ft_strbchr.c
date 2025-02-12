/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strbchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 13:13:56 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/16 13:13:57 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strbchr(char *s, size_t n, char c)
{
	while (n > 1)
	{
		n--;
		s[n] = c;
	}
}
