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
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_tack
{
	int			*stack;
	int			length;
}				t_tack;
char			*ft_strnew(size_t size);
int				make_stack(int argc, char **argv, t_tack *stk_one,
				t_tack *stk_two);
int				check_stacks(t_tack stk_one, t_tack stk_two);
int				operate(char *line, int i, t_tack *a, t_tack *b);
char			*ft_strjoin(char const *s1, char const *s2);
int				check_duplicates(int argc, char **argv);
void			simplify_stack(t_tack *a);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
void			solver(t_tack a, t_tack b, char **solution);

#endif
