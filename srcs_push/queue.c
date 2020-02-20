/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 13:37:26 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/20 13:37:27 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_to_queue(t_node *node, t_qnode *queue, t_data *data)
{
	t_node *queue;
	t_qnode	*const new = ft_memalloc(sizeof(t_qnode));

	new->next = NULL;
	new->node = node;
	new->weight = node->weight;
	if (!data->queue)
		data->queue = 
	while (queue->next && node->weight < queue->weight)
		queue = queue->next;
	if (stacks_match(node->stacks, queue->node->stacks))
	{
		ft_free(new);
		return ;
	}
	while (queue->next && node->weight == queue->next->weight)
	{
		queue = queue->next;
		if (stacks_match(node->stacks, queue->node->stacks))
		{
			ft_free(new);
			return ;
		}
	}
	new->next = queue->next->next;
	queue->next = new;
}

t_node	*next_from_queue(t_data *data)
{
	t_node	*ret;
	t_qnode	*temp;

	if (!ret)
		return (NULL);
	temp = data->queue;
	ret = temp->node;
	data->queue = data->queue->next;
	ft_free(temp);
	return (ret);
}
