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

void	display_solution(char *solution)
{
	ft_putstr(solution);
	free(solution);
}

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
	if (a.len > 0)
		ft_putnbr(a.stack[0]);
	i = 1;
	while (i < a.len)
	{
		ft_putchar(' ');
		ft_putnbr(a.stack[i]);
		i++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

void	display_node(t_node node)
{
	int i;

	ft_putstr("Instructions: ");
	ft_putnbr(node.n_instr);
	ft_putstr("  ");
	if (node.instr && node.instr[0])
	{
		i = 0;
		while (node.instr[i])
		{
			if (node.instr[i] == '\n')
				write(1, " ", 1);
			else
				write(1, node.instr + i, 1);
			i++;
		}
	}
	putchar('\n');
	ft_putstr("Weight :");
	ft_putnbr(node.weight);
	ft_putchar('\n');
	if (node.a->len > 0)
		display_array(*(node.a), "a");
	else
		ft_putstr("\n\n\n\n");
	if (node.b->len > 0)
		display_array(*(node.b), "b");
	else
		ft_putstr("\n\n\n\n");
	ft_putchar('\n');
}

void	display_forest(t_node *root)
{
	display_node(*root);
	if (root->child)
	{
		ft_putstr("Child:\n");
		display_forest(root->child);
	}
	else
		ft_putstr("No child:\n\n");
	if (root->next)
	{
		ft_putstr("Brother:\n");
		display_forest(root->next);
	}
	else
		ft_putstr("No brother:\n\n");
}
