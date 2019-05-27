/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   word_helper.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/22 11:22:47 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/05/22 11:22:48 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_HELPER_H
# define WORD_HELPER_H
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_word
{
	char			word[3];
	struct s_word	*next;
	struct s_word	*prev;
}					t_word;
char				*ft_strncpy(char *dst, const char *src, size_t len);

#endif
