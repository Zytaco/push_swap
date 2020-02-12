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

static void		add_int(t_node *n, int x)
{
	t_tack new_a;

	if (n->stacks.a.size < 0)
		n->stacks.a.size = 0;
	new_a.size = n->stacks.a.size + 1;
	new_a.stack = ft_memalloc(sizeof(int) * (new_a.size));
	ft_memcpy(new_a.stack, n->stacks.a.stack, sizeof(int) * n->stacks.a.size);
	new_a.stack[new_a.size - 1] = x;
	ft_free(n->stacks.a.stack);
	n->stacks.a = new_a;
}

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

static void		add_randoms(int n, t_data data)
{
	struct timeval	the_time;

	gettimeofday(&the_time, NULL);
	srand(the_time.tv_usec);
	while (n > 0)
	{
		if (rand() % 2 == 0)
			add_int(data.start, rand());
		else
			add_int(data.start, INT32_MIN + rand());
		n--;
	}
}

/*
** RAND_MAX should be the max int value.
*/

static int		flag_check(char *arg, char *next, t_data *data)
{
	if (ft_strequ(arg, "-r"))
	{
		if (!next || !int_check(next))
			data->flags.help = YES;
		else
		{
			data->flags.n_random = atoi(next);
			arg[0] = '\0';
			next[0] = '\0';
		}
		add_randoms(data->flags.n_random, *data);
	}
	else if (ft_strequ(arg, "-v"))
		data->flags.verbose = YES;
	else if (ft_strequ(arg, "-h"))
		data->flags.help = YES;
	else
		return (0);
	return (1);
}

void			parse(char **argv, t_data *data)
{
	char		**args;
	int			i;
	int			j;

	i = ft_strequ(argv[0], "./push_swap") ? 1 : 0;
	while (argv[i] && data->flags.help == NO && data->flags.random == NO)
	{
		args = ft_strfsplit(argv[i], ft_iswhitespace);
		j = 0;
		while (args && args[j])
		{
			if (args[j][0] == '-' && !ft_isdigit(args[j][1]))
				flag_check(args[j], args[j + 1], data);
			else if (int_check(args[j]))
				add_int(data->start, ft_atoi(args[j]));
			else
				display_input_error(args[j], &data->flags);
			j++;
		}
		i++;
		ft_free(args);
		args = NULL;
	}
}
