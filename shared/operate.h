/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operate.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:52:42 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/25 14:52:44 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATE_H
# define OPERATE_H

typedef struct	s_tack
{
	int			*stack;
	int			length;
}				t_tack;
int				ft_strcmp(const char *s1, const char *s2);
void			operate_helper(char *line, int i, t_tack a, t_tack b);

#endif
