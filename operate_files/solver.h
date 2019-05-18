/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 09:57:07 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/15 09:57:08 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include <stdlib.h>

typedef struct	s_tack
{
	int			*stack;
	int			length;
}				t_tack;
void			split(t_tack *a, t_tack *b, int pivot, char **solution);
void			optimal_rotation(t_tack a, char **solution);
char			*ft_strfajoin(char **s1, char const *s2);

#endif
