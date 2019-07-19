/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_help.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 13:25:14 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/09 13:25:14 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_HELP_H
# define SIMPLE_HELP_H

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
	int				tail;
}					t_tack;
int					find_biggest(int *stk, int len, int length);
void				swap(t_tack stk);
t_word				*new_to_list(t_word *start, char s[3]);
void				rotation_a(t_tack st, int i, t_word *list);

#endif
