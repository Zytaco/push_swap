/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/26 10:21:57 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/26 10:21:58 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

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
void				rotation_a(t_tack a, int i, t_word *list);
void				rotation_b(t_tack st, int i, t_word *list);
t_word				*new_to_list(t_word *start, char s[3]);
int					push(t_tack *a, t_tack *b);
void				swap(t_tack stk);
int					swap_a_maybe(t_tack stack, t_word *start);
void				do_thing_a(char *s, t_word *start, t_tack *a, t_tack *b);
void				do_thing_b(char *s, t_word *start, t_tack *a, t_tack *b);
int					find_lowest(int *stk, int len);

#endif
