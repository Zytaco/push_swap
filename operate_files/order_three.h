/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   order_three.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 16:15:59 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/07 16:15:59 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_THREE_H
# define ORDER_THREE_H

typedef struct		s_word
{
	char			word[4];
	struct s_word	*next;
	struct s_word	*prev;
}					t_word;
typedef struct		s_tack
{
	int				*stack;
	int				length;
}					t_tack;
int					find_lowest(int *stk, int len);
int					find_biggest(int *stk, int len);
void				do_thing_a(char *s, t_word *start, t_tack *a, t_tack *b);
void				do_thing_b(char *s, t_word *start, t_tack *a, t_tack *b);


#endif
