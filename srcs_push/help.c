/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   help.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 17:11:27 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/06 17:11:28 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_help(void)
{
	ft_putstr("usage: ./push_swap ");
	ft_putendl("[-v] [-s] [-r <int>] [-h] [<int> <int>...]\n");
	ft_putendl("-v:    Verbose mode.");
	ft_putendl("-r:    random mode, random integers will be generated as");
	ft_putendl("       input and put in the position of the -r flag.");
	ft_putendl("       The amount of integers will equal the following int.");
	ft_putendl("       Note: The following int must be positive");
	ft_putendl("       Note: The generated ints will be displayed unless ");
	ft_putendl("       the -s tag is active.");
	ft_putendl("-s:    Silent mode, silences -r and disables -v tag.");
	ft_putendl("-h:    Help. Displays usage.");
	ft_putendl("-d:    Destinations. Displays destinations with stacks.");
	ft_putendl("-p:    Points. Displays points with stacks.");
	ft_printf("<int>:  Any number between %d and %d\n", INT32_MIN, INT32_MAX);
	ft_error(NULL);
}
