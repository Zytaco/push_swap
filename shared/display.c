/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 14:38:51 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/19 14:38:52 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	diplay_seperator(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar('-');
		i++;
	}
	ft_putchar('\n');
}

void	display_array(t_array a, char *name)
{
	int i;

	if (name)
	{
		ft_putstr(name);
		ft_putchar(' ');
	}
	ft_putstr("length: ");
	ft_putnbr(a.len);
	ft_putchar('\n');
	diplay_seperator(a.len * 3);
	ft_putnbr(a.stack[0]);
	i = 1;
	while (i < a.len)
	{
		ft_putchar(' ');
		ft_putnbr(a.stack[i]);
		i++;
	}
	ft_putchar('\n');
}
