/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   improve_solution.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:28:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/09 12:28:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMPROVE_SOLUTION_H
# define IMPROVE_SOLUTION_H
# include <unistd.h>

typedef struct		s_word
{
	char			word[3];
	struct s_word	*next;
	struct s_word	*prev;
}					t_word;
typedef struct		s_tack
{
	int				*stack;
	int				length;
}					t_tack;
int					two_checks(char a[3], char b[3]);
int					three_checks(char a[3], char b[3], char c[3]);
int					ss_checks(char a[3], char b[3]);

#endif
