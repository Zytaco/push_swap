/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimal_rotation.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 11:26:38 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/16 11:26:38 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMAL_ROTATION_H
# define OPTIMAL_ROTATION_H

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
char				*ft_strfajoin(char **s1, char const *s2);
t_word				*new_to_list(t_word *start, char s[3]);
void				rotate(int *stk, int len);
void				reverse_rotate(int *stk, int len);
void				swap(t_tack stk);

#endif
