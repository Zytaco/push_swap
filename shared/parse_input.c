/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 15:10:03 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/12 15:10:03 by jheeresm      ########   odam.nl         */
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
		ft_putchar('\n');
	exit(0);
}

static int	get_stack_size(int argc, char **argv, int arg)
{
	int i;
	int size;

	size = 0;
	while (arg < argc)
	{
		i = 0;
		if (argv[arg][0] == '-')
		{
			arg++;
			continue ;
		}
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

void		put_int_in_stack(t_array a, int argc, char **argv)
{
	int i;
	int pos;
	int arg;

	pos = 0;
	arg = 0;
	while (arg < argc && argv[arg][0] == '-')
		arg++;
	while (arg < argc)
	{
		i = 0;
		while (argv[arg][i] && !ft_isdigit(argv[arg][i]))
			i++;
		if (ft_isint(argv[arg] + i, -1))
		{
			a.stack[pos] = ft_atoi(argv[arg] + i);
			pos++;
		}
		else
			parse_error(argv[arg] + i, "Bad integer");
		while (argv[arg][i] && !ft_isdigit(argv[arg][i]))
			i++;
		if (argv[arg][i] == '\0')
			arg++;
	}
}

static int	if_flag_then_store(char *arg, t_data *data)
{
	if (arg[0] == '-')
	{
		if (ft_strequ("-h", arg) || ft_strequ("--help", arg))
			display_help();
		else if (ft_strequ("-v", arg))
			data->flags.v = 1;
		else
			ft_error("ERROR: option not recognised");
		return (1);
	}
	return (0);
}

int			parse_input(t_data *data, int argc, char **argv)
{
	int		i;
	int		size;

	i = 1;
	while (argv[i] && if_flag_then_store(argv[i], data))
		i++;
	size = get_stack_size(argc, argv, i);
	return (size);
}
