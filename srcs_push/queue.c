/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 13:33:21 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/28 13:33:21 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	slip_in(t_node *new, t_node *bef, t_node *aft)
{
	new->next = aft;
	new->prev = bef;
	if (bef)
	{
		bef->next = new;
		new->parent = bef->parent;
	}
	if (aft)
	{
		aft->prev = new;
		new->parent = aft->parent;
		if (aft->parent && aft->parent == aft)
			new->parent->child = new;
	}
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

t_node	*make_tree(t_node *top, t_node *bot)
{
	if (top->weight > bot->weight)
		return (make_tree(bot, top));
	pop(bot, NULL);
	bot->parent = top;
	top->members += bot->members;
	insert_new(&(top->child), bot);
	return (top);
}

void	insert_new(t_node **start, t_node *new)
{
	t_node *bef;
	t_node *aft;

	bef = NULL;
	aft = *start;
	while (aft && new->weight > aft->weight)
	{
		bef = aft;
		aft = aft->next;
	}
	slip_in(new, bef, aft);
	while (new->next && new->members == new->next->members)
		new = make_tree(new, new->next);
	if (!new->prev)
		*start = new;
}

t_node	*pop_min(t_node **queue)
{
	t_node *min;
	t_node *n;

	min = *queue;
	n = *queue;
	while (n)
	{
		if (n->weight < min->weight)
			min = n;
		n = n->next;
	}
	pop(min, queue);
	while (min->child)
	{
		n = min->child;
		pop(min->child, queue);
		insert_new(queue, n);
	}
	return (min);
}

t_node	*new_node(t_array *a, t_array *b, char *instr, int n_instr)
{
	t_node *new;

	if (!instr)
		ft_error("ft_strjoin failed to allocate");
	new = malloc(sizeof(t_node));
	if (!new)
		ft_error("new_node() failed to allocate");
	new->parent = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->child = NULL;
	new->members = 1;
	if (new->instr)
		free(new->instr);
	new->instr = instr;
	new->n_instr = n_instr;
	new->a = a;
	new->b = b;
	get_state_score(new);
	// display_node(*new);
	return (new);
}
