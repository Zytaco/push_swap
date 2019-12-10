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

void	free_node(t_node *n)
{
	if (!n)
		return ;
	if (n->a)
		free(n->a);
	if (n->b)
		free(n->b);
	if (n->instr)
		free(n->instr);
	free(n);
}

void	pop(t_node *n, t_node **start)
{
	if (start && *start == n)
		*start = n->next;
	if (n->prev)
		n->prev->next = n->next;
	if (n->next)
		n->next->prev = n->prev;
	if (n->parent && n->parent->child == n)
		n->parent->child = n->next;
	n->next = NULL;
	n->prev = NULL;
	n->parent = NULL;
}

t_node	*full_pop(t_node *n, t_node **queue)
{
	t_node *child;

	pop(n, queue);
	while (n->child)
	{
		child = n->child;
		pop(n->child, queue);
		insert_new(queue, child);
	}
	return (n);
}

t_node	*pop_min(t_node **queue)
{
	t_node *min;
	t_node *n;

	min = *queue;
	n = (*queue)->next;
	while (n)
	{
		if (n->weight < min->weight)
			min = n;
		n = n->next;
	}
	return (full_pop(min, queue));
}

t_node	*new_bare_node(void)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_error("new_node() failed to allocate");
	new->parent = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->child = NULL;
	new->members = 1;
	new->instr = NULL;
	new->n_instr = 0;
	new->a = NULL;
	new->b = NULL;
	return (new);
}

t_node	*new_node(t_array *a, t_array *b, char *new_instr, int n_used)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		ft_error("new_node() failed to allocate");
	new->parent = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->child = NULL;
	new->members = 1;
	new->instr = new_instr;
	new->n_instr += n_used;
	new->a = a;
	new->b = b;
	get_state_score(new, *a, *b);
	return (new);
}


