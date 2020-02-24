/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stradd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 14:41:31 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/09 14:41:31 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_stradd(const char **replace, const char *add)
{
	char *new;

	if (!*replace)
		*replace = add;
	else if (!*add)
		return ;
	else
	{
		new = ft_strjoin(*replace, add);
		free((void *)*replace);
		*replace = new;
	}
}
