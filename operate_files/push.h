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
# include "solver.h"

void				a_rotate_x_to(int target, int pos, t_tack a, t_word *start);
void				b_rotate_x_to(int target, int pos, t_tack b, t_word *start);
void				rotation_a(t_tack st, int i, t_word *list);
void				rotation_b(t_tack st, int i, t_word *list);
t_word				*new_to_list(t_word *start, char s[3]);
int					push(t_tack *a, t_tack *b);
void				swap(t_tack stk);
int					swap_a_maybe(t_tack stack, t_word *start);
int					swap_b_maybe(t_tack stack, t_word *start);
void				do_thing_a(char *s, t_word *start, t_tack *a, t_tack *b);
void				do_thing_b(char *s, t_word *start, t_tack *a, t_tack *b);
int					find_lowest(int *stk, int len, int length);

#endif
