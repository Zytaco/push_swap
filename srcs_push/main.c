/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 13:19:35 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 13:19:35 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_data	data;
	t_data	**parts;
	int		i;

	parse_input(&data, argc , argv);
	data.solution = ft_strnew(0);
	solve(data);
	check_solution(data);
	print_solution(data);
}
