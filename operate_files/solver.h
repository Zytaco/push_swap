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
void				split(t_tack *a, t_tack *b, int width, t_word *start);
void				optimal_rotation(t_tack a, t_word *list, char name);
char				*ft_strfajoin(char **s1, char const *s2);
t_word				*new_to_list(t_word *start, char s[3]);
int					push(t_tack *a, t_tack *b);
void				rotate(int *stk, int len);
void				reverse_rotate(int *stk, int len);
void				swap(t_tack stk);
void				rotation(t_tack a, int i, t_word *list, char name);
void				rotate_to_front(t_tack *a, t_word *start);
void				push_four(t_tack *a, t_tack *b, t_word *start);
void				push_remainder(t_tack *a, t_tack *b, t_word *start);
void				push_all(t_tack *a, t_tack *b, t_word *start);
int					swap_a_maybe(t_tack stack, t_word *start);
int					rotate_a_maybe(t_tack a, t_word *list);
int					rotate_b_maybe(t_tack b, t_word *list, int biggest);
int					find_biggest(int *stk, int len);

#endif
