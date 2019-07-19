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
# define BLOCK 32

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
int					get_next_line(const int fd, char **line);
void				split_a(t_tack *a, t_tack *b, int width, t_word *start);
void				split_b(t_tack *a, t_tack *b, int width, t_word *start);
char				*ft_strfajoin(char **s1, char const *s2);
t_word				*new_to_list(t_word *start, char s[3]);
int					push(t_tack *a, t_tack *b);
void				rotate(int *stk, int len);
void				reverse_rotate(int *stk, int len);
void				swap(t_tack stk);
void				rotation_a(t_tack st, int i, t_word *list);
void				rotation_b(t_tack st, int i, t_word *list);
void				rotate_to_front(t_tack *stk, t_word *start, int target,
					char stack);
void				push_all(t_tack *a, t_tack *b, t_word *start);
int					swap_a_maybe(t_tack stack, t_word *start);
int					swap_b_maybe(t_tack b, t_word *start);
int					rotate_a_maybe(t_tack a, t_word *list);
int					rotate_b_maybe(t_tack b, t_word *list, int biggest);
int					find_biggest(int *stk, int len, int length);
void				do_thing_a(char *s, t_word *start, t_tack *a, t_tack *b);
void				do_thing_b(char *s, t_word *start, t_tack *a, t_tack *b);
int					ordered_a(int *stk, int len);
int					ordered_b(int *stk, int len);
void				lowest_to_front(t_tack a, t_word *start);
int					find_lowest(int *stk, int len, int length);
void				a_rotate_x_to(int target, int pos, t_tack a, t_word *start);
void				b_rotate_x_to(int target, int pos, t_tack b, t_word *start);
void				sort_a(t_tack *a, t_tack *b, t_word *start);

#endif
