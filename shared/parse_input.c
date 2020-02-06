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

static int		int_check(char *arg)
{
	static char	max[11] = "2147483647";
	int			i;
	int			good;

	if (ft_strequ("-2147483648", arg))
		return (1);
	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		arg++;
	good = 1;
	i = 0;
	while (arg[i] && i < 10)
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		if (arg[i] > max[i])
			good = 0;
		i++;
	}
	if (i == 10)
		return (good);
	return (1);
}

/*
** RAND_MAX should be the max int value.
*/
void			add_randoms(int randoms, t_data *data)
{
	int				rand_n;
	struct timeval	the_time;

	gettimeofday(&the_time, NULL);
	srand(the_time.tv_usec);
	while (randoms > 0)
	{
		if (rand() % 2 == 0)
			rand_n = rand();
		else
			rand_n = INT32_MIN + rand();
		add_last(&(data->stacks.a), new_piece(rand_n));
		randoms--;
	}
}

static int		flag_check(char **argv, int *i, t_flags *flags, t_data *data)
{
	if (ft_strequ(argv[*i], "-r"))
	{
		if (!argv[*i + 1] || !int_check(argv[*i + 1]))
			flags->help = 1;
		else
		{
			flags->random = 1;
			(*i)++;
			add_randoms(ft_atoi(argv[*i]), data);
		}
	}
	else if (ft_strequ(argv[*i], "-v"))
		flags->verbose = 1;
	else if (ft_strequ(argv[*i], "-s"))
		flags->silent = 1;
	else if (ft_strequ(argv[*i], "-h"))
		flags->help = 1;
	else if (ft_strequ(argv[*i], "-d"))
		flags->destinations = 1;
	else if (ft_strequ(argv[*i], "-p"))
		flags->points = 1;
	else
		return (0);
	return (1);
}

static void		init_data(t_data *data)
{
	data->flags.verbose = 0;
	data->stacks.a.first = NULL;
	data->stacks.a.size = 0;
	data->stacks.b.first = NULL;
	data->stacks.b.size = 0;
}

t_data			parse(char **argv)
{
	t_data		data;
	char		**input;
	int			i;

	input = ft_array_expand(argv + 1, " \t\n\f\r\v");
	init_data(&data);
	i = 0;
	while (input[i])
	{
		if (input[i][0] == '-' && !ft_isdigit(input[i][1]))
			flag_check(input, &i, &(data.flags), &data);
		else if (int_check(input[i]))
			add_last(&data.stacks.a, new_piece(ft_atoi(input[i])));
		else
		{
			ft_putstr("UNRECOGNISED ARGUMENT: ");
			ft_putstr(input[i]);
			ft_putstr("\n");
			data.flags.help = 1;
		}
		i++;
	}
	return (data);
}
