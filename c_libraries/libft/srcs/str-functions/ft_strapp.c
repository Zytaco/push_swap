/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strapp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 15:39:49 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/07 15:39:49 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strapp(char **s, const char *app)
{
	char		*new;
	const int	app_len = ft_strlen(app);
	const int	s_len = ft_strlen(*s);

	if (!s)
		return (NULL);
	if (!app)
		return (*s);
	if (!*s)
	{
		*s = ft_strdup(app);
		return (*s);
	}
	new = ft_strnew(s_len + app_len);
	ft_strcpy(new, *s);
	ft_strcpy(new + s_len, app);
	new[s_len + app_len] = '\0';
	free(*s);
	*s = new;
	return (new);
}
