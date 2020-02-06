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

int			main(int argc, char **argv)
{
	t_data		data;

	data = parse(argc, argv);
	if (data.flags.h)
	{
		display_help();
		return (1);
	}
	duplicate_check(*data.a);
	normalisestck(*data.a);
	display_ops(solver(data));
	return (1);
}
