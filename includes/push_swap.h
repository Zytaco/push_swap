/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 13:20:21 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 13:20:21 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../c_libraries/libft/includes/libft.h"
# include "../c_libraries/libsort/includes/libsort.h"

#define PART_SIZE 5

typedef struct		s_data
{
	t_array			*a;
	t_array			*b;
	char			*solution;
}					t_data;

t_data				*parse_input(t_data *data, int argc, char **argv);
void				add_operation(t_data *data, char *op);

#endif
