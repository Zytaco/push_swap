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

static void	store_flag(t_data *data, char *arg)
{
	if (arg[0] == '-' && arg[1] == 'v' && arg[2] == '\0')
		data->flags.v = 1;
	else
		parse_error(arg, "Bad flag\n");
}

static int	count_ints(char *arg)
{
	int i;
	int size;
	int len;

	size = 0;
	i = 0;
	while (arg[i])
	{
		i += ft_skip_whitespace(arg + i);
		len = 0;
		if (arg[i] == '-')
			len++;
		len = ft_skipstr(arg + i + len, "1234567890");
		if (len == 0)
			parse_error(arg, "ERROR: bad arg");
		else if (ft_isint(arg + i, len))
			size++;
		else
			parse_error(arg, "ERROR: bad int");
		i += len;
	}
	return (size);
}

void		put_int_in_stack(t_array a, int argc, char **argv)
{
	int arg;
	int i;
	int pos;

	pos = 0;
	arg = 1;
	while (arg < argc)
	{
		if (!(argv[arg][0] == '-' && !ft_isdigit(argv[arg][1])))
		{
			i = 0;
			while (argv[arg][i])
			{
				i += ft_skip_whitespace(argv[arg] + i);
				a.stack[pos] = ft_atoi(argv[arg] + i);
				pos++;
				if (argv[arg][i] == '-')
					i++;
				i += ft_skipstr(argv[arg] + i, "1234567890");
			}
		}
		arg++;
	}
}

int			count_ints_store_flags(t_data *data, int argc, char **argv)
{
	int		i;
	int		size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
			store_flag(data, argv[i]);
		else
			size += count_ints(argv[i]);
		i++;
	}
	return (size);
}
