/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_and_make.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:38:24 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/25 14:38:27 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_AND_MAKE_H
# define CHECK_AND_MAKE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_tack
{
	int			*stack;
	int			length;
}				t_tack;
int				ft_atoi(const char *str);

#endif
