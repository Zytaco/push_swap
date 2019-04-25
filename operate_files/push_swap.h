/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:53:39 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/25 13:53:39 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_tack
{
	int			*stack;
	int			length;
}				t_tack;
char			*ft_strnew(size_t size);
int				make_stack(int argc, char **argv, t_tack *stk_one,
				t_tack *stk_two);
int				check_stacks(t_tack stk_one, t_tack stk_two);
void			operate(char *line, int i, t_tack a, t_tack b);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
