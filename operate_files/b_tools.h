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

#endif
