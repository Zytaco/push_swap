/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exploration.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 14:02:26 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/20 14:02:26 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#define SIZE 5


int		make_sequence(size_t size)*
{
	size_t	i;
	int		*const new = ft_memalloc(size);

	i = 0;
	while (i < size)
	{
		new[i] = i;
		i++;
	}
	return (new);
}

int		calc_list_size(int size)
{
	int spots;
	int ret;

	ret = 1;
	spots = 2 * size;
	while (size > 0)
	{
		ret *= spots;
		size--;
	}
	return (ret);
}

int		main(void)
{
	t_node		start;
	t_stacks	start_stacks;
	t_node		*const list = ft_memalloc(calc_list_size(SIZE));

	start.depth = 0;
	start.desc = NULL;
	start.ops = NULL;
	start.parent = NULL;
	start_stacks.a.stack = make_sequence(SIZE);
	start_stacks.a.size = SIZE;
	start_stacks.a.stack = make_sequence(0);
	start_stacks.a.size = 0;
	start.stacks = start_stacks;

}
