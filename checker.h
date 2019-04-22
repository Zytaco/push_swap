/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 14:48:18 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/22 14:48:21 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>

typedef struct	s_tack
{
	int			*stack;
	int			length;
}				t_tack;
int				check_if_int(char *s);
void			operate(char *line, struct s_tack a, struct s_tack b);
void			operate_helper(char *line, struct s_tack a, struct s_tack b);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				get_next_line(const int fd, char **line);

#endif
