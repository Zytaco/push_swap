/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   b_tools.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:55:26 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/09 12:55:27 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_TOOLS_H
# define B_TOOLS_H
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
void				shuffle_swap(t_tack stk, char name, t_word *start);
void				swap(t_tack stk);
t_word				*new_to_list(t_word *start, char s[3]);
void				shuffle_swap(t_tack stk, char name, t_word *start);
int					b_maybes(t_tack *a, t_tack *b, t_word *start);
int					find_lowest(int *stk, int len);
int					find_biggest(int *stk, int len);
void				rotate(int *stk, int len);
void				reverse_rotate(int *stk, int len);
void				do_thing_a(char *s, t_word *start, t_tack *a, t_tack *b);
int					push(t_tack *a, t_tack *b);
void				rotation_b(t_tack a, int i, t_word *list);
int					swap_a_maybe(t_tack stack, t_word *start);
int					swap_b_maybe(t_tack stack, t_word *start);

#endif
