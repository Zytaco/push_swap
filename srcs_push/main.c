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

int		main(int argc, char **argv)
{
	t_data	data;
	t_array a;
	t_array b;
	int		size;

	data.flags.v = 0;
	data.sol->solution = ft_strnew(0);
	size = parse_input(&data, argc, argv);
	if (size >= INT32_MAX)
		ft_error("ERROR: Too much input\n");
	data.a.stack = malloc(sizeof(int) * size);
	data.a.len = size;
	data.b.stack = malloc(sizeof(int) * size);
	data.b.len = 0;
	duplicate_check(a);
	check_int_put_in_stack(data.a, argc, argv);
	normalise_stack(a);
	if (ordered(a), 'a')
		return (1);
	solver(data);
}
