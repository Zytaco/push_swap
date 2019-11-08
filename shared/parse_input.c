/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 13:30:09 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/08 13:30:09 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	parse_error(char *line, char *message)
{
	ft_putstr(message);
	if (line)
	{
		ft_putendl(" at:");
		ft_putendl(line);
	}
	else
		ft_putchar("\n");
	exit(0);
}

static int	get_stack_size(int argc, char **argv, int arg)
{
	int i;
	int size;

	size = 0;
	while (argv[arg])
	{
		i = 0;
		while (argv[arg][i] && !ft_isdigit(argv[arg][i]))
			i++;
		if (ft_isdigit(argv[arg][i]))
			size++;
		while (argv[arg][i] && !ft_isdigit(argv[arg][i]))
			i++;
		if (argv[arg][i] == '\0')
			arg++;
	}
	return (size);
}

static void	check_int_put_in_stack(t_array *a, int argc, char **argv, int arg)
{
	int i;
	int pos;

	pos++;
	while (argv[arg])
	{
		i = 0;
		while (argv[arg][i] && !ft_isdigit(argv[arg][i]))
			i++;
		if (ft_isint(argv[arg][i], -1))
		{
			a->array[pos] = ft_atoi(argv[arg][i]);
			pos++;
		}
		else
			parse_error(argv[arg][i], "Bad integer");
		while (argv[arg][i] && !ft_isdigit(argv[arg][i]))
			i++;
		if (argv[arg][i] == '\0')
			arg++;
	}
}

t_data		*parse_input(t_data *data, int argc, char **argv)
{
	int		i;
	int		size;

	i = 1;
	while (argv[i] && if_flag_then_store(argv[i], data))
		i++;
	size = 0;
	size = get_stack_size(argc, argv, i);
	data->a = sort_new_array(NULL, size);
	data->b = sort_new_array(NULL, size);
	data->b->size = 0;
	check_int_put_in_stack(data->a, argc, argv, i);
	return (data);
}
