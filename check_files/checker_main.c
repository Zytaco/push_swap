/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 14:48:35 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/04/22 14:48:39 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "checker_main.h"

// #include "display_stacks.c"

static int	check_operation(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		return (1);
	else if (ft_strcmp(line, "sb") == 0)
		return (1);
	else if (ft_strcmp(line, "ss") == 0)
		return (1);
	else if (ft_strcmp(line, "pa") == 0)
		return (1);
	else if (ft_strcmp(line, "pb") == 0)
		return (1);
	else if (ft_strcmp(line, "ra") == 0)
		return (1);
	else if (ft_strcmp(line, "rb") == 0)
		return (1);
	else if (ft_strcmp(line, "rr") == 0)
		return (1);
	else if (ft_strcmp(line, "rra") == 0)
		return (1);
	else if (ft_strcmp(line, "rrb") == 0)
		return (1);
	else if (ft_strcmp(line, "rrr") == 0)
		return (1);
	else
		return (-2);
}

static int	get_operations(t_tack stk_one, t_tack stk_two)
{
	char	*line;
	int		ret;

	ret = get_next_line(0, &line);
	while (ret == 1 && line != NULL && line[0] != 0)
	{
		ret = check_operation(line);
		if (ret >= 1)
		{
			operate(line, -1, stk_one, stk_two);
			ret = get_next_line(0, &line);
		}
	}
	if (ret < 0)
	{
		write(1, "Error\n", 6);
		return (ret);
	}
	return (ret);
}

int			main(int argc, char **argv)
{
	t_tack	stk_one;
	t_tack	stk_two;

	if (argc <= 1)
		return (1);
	if (make_stack(argc, argv, &stk_one, &stk_two) == 0)
	{
		write(1, "improper input\n", 15);
		return (1);
	}
	if (get_operations(stk_one, stk_two) <= -1)
	{
		free(stk_one.stack);
		free(stk_two.stack);
		return (1);
	}
	else if (check_stacks(stk_one, stk_two) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	// display_stacks(stk_one, stk_two);
	free(stk_one.stack);
	free(stk_two.stack);
	return (1);
}
