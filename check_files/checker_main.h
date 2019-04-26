/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_main.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:26:28 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/25 14:26:28 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_MAIN_H
# define CHECKER_MAIN_H

typedef struct	s_tack
{
	int			*stack;
	int			length;
}				t_tack;
int				make_stack(int argc, char **argv, t_tack *stk_one,
				t_tack *stk_two);
int				ft_strcmp(const char *s1, const char *s2);
int				get_next_line(const int fd, char **line);
int				operate(char *line, int i, t_tack *a, t_tack *b);
int				check_stacks(t_tack stk_one, t_tack stk_two);
int				check_duplicates(int argc, char **argv);

#endif
