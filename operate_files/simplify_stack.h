/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simplify_stack.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 17:06:20 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/09 17:06:20 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLIFY_STACK_H
# define SIMPLIFY_STACK_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_tack
{
	int			*stack;
	int			length;
	int			tail;
}				t_tack;
int				find_lowest(int *stk, int len, int length);

#endif
