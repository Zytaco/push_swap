/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_tools.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 11:57:53 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/12/05 11:57:53 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_node(t_node **n)
{
	if (!n)
		return ;
	ft_free((*n)->desc);
	(*n)->desc = NULL;
	ft_free((void*)(*n)->ops);
	(*n)->ops = (const t_ops*)NULL;
	(*n)->stacks.a.size = 0;
	ft_free((*n)->stacks.a.stack);
	(*n)->stacks.a.stack = NULL;
	(*n)->stacks.b.size = 0;
	ft_free((*n)->stacks.b.stack);
	(*n)->stacks.b.stack = NULL;
	ft_free(*n);
	*n = NULL;
}

void	free_all_nodes(t_node *node)
{
	int i;

	if (node->parent)
	{
		free_all_nodes(node->parent);
		return ;
	}
	i = 0;
	while (node->desc[i])
	{
		node->desc[i]->parent = NULL;
		free_all_nodes(node->desc[i]);
		i++;
	}
	free_node(&node);
}
