/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:11:52 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 15:11:53 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		error_int(char *message, int x)
{
	ft_putendl(message);
	ft_putnbr(x);
	exit(0);
}

void		duplicate_check(t_array a)
{
	int i;
	int j;

	i = 0;
	while (i < a.len - 1)
	{
		j = 1;
		while (j < a.len)
		{
			if (a.stack[i] == a.stack[j])
				error_int("ERROR: duplicate int", a.stack[i]);
			j++;
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_data	data;
	t_array a;
	t_array b;
	int		size;

	data.flags.v = 0;
	data.sol->solution = ft_strnew(0);
	size = count_ints_store_flags(&data, argc, argv);
	if (size >= INT32_MAX)
		ft_error("ERROR: Too much input\n");
	data.a.stack = malloc(sizeof(int) * size);
	data.a.len = size;
	data.b.stack = malloc(sizeof(int) * size);
	data.b.len = 0;
	put_int_in_stack(data.a, argc, argv);
	duplicate_check(a);
	normalise_stack(a);
	if (ordered(a, 'a'))
		return (1);
	solver(data);
}
