/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_skip_whitespace.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 16:07:26 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/18 16:07:26 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_skip_whitespace(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	return (i);
}
