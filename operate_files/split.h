/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 12:24:14 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/16 12:24:14 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H
# include <unistd.h>

typedef struct	s_tack
{
	int			*stack;
	int			length;
}				t_tack;
char			*ft_strfajoin(char **s1, char const *s2);

#endif
