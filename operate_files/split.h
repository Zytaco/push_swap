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
t_word				*new_to_list(t_word *start, char s[3]);
char				*ft_strfajoin(char **s1, char const *s2);
int					push(t_tack *a, t_tack *b);
void				rotate(int *stk, int len);
void				reverse_rotate(int *stk, int len);
void				swap(t_tack stk);
int					find_lowest(int *stk, int len, int length);
int					find_biggest(int *stk, int len, int length);
int					swap_a_maybe(t_tack stack, t_word *start);
int					swap_b_maybe(t_tack stack, t_word *start);
int					ordered_a(int *stk, int len);
void				do_thing_a(char *s, t_word *start, t_tack *a, t_tack *b);
void				do_thing_b(char *s, t_word *start, t_tack *a, t_tack *b);
int					ordered_b(int *stk, int len);

#endif
