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
	ft_putchar('\n');
	exit(0);
}

void		duplicate_check(t_array a)
{
	int i;
	int j;

	i = 1;
	while (i < a.len)
	{
		j = 0;
		while (j < i)
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
	t_data		data;
	int			size;

	data.flags.v = 0;
	size = count_ints_store_flags(&data, argc, argv);
	if (size >= INT32_MAX)
		ft_error("ERROR: Too much input");
	if (size <= 1)
		exit(0);
	data.a = new_array(size);
	data.b = new_array(0);
	put_int_instck(*data.a, argc, argv);
	duplicate_check(*data.a);
	normalisestck(*data.a);
	solver(data);
}
