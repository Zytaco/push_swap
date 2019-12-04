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
	new->prev = bef;
	new->next = aft;
	if (bef)
	{
		bef->next = new;
		new->parent = bef->parent;
	}
	if (aft)
	{
		aft->prev = new;
		new->parent = aft->parent;
		if (new->parent->child == aft)
			new->parent->child = new;
	}
}

t_node	*make_tree(t_node *a, t_node *b)
{
	t_node *temp;

	if (a->weight > b->weight)
	{
		temp = a;
		a = b;
		b = temp;
	}
	a->descendants += b->descendants + 1;
	if (!a->child)
		a->child = b;
	else
		insert_new(&(a->child), b);
	return (a);
}

void	insert_new(t_node **start, t_node *new)
{
	t_node *bef;
	t_node *aft;

	if (!new)
		return ;
	bef = NULL;
	aft = *start;
	while (aft && new->descendants > aft->descendants)
	{
		bef = aft;
		aft = aft->next;
	}
	if (!bef)
		*start = new;
	if (bef && new->descendants == bef->descendants)
		slip_in(make_tree(new, bef), bef->prev, bef->next);
	else if (aft && new->descendants == aft->descendants)
		slip_in(make_tree(new, aft), aft->prev, aft->next);
	else
		return ;
}

void	pop(t_node *pop, t_node **start)
{
	if (pop->prev)
		pop->prev->next = pop->next;
	if (pop->next)
		pop->next->next = pop->prev;
	if (pop->parent)
	{
		pop->parent->descendants -= pop->descendants + 1;
		if (!pop->prev)
			pop->parent->child = pop->next;
	}
	if (pop->child)
		insert_new(start, pop->child);
	pop->prev = NULL;
	pop->next = NULL;
	pop->parent = NULL;
	pop->child = NULL;
}

t_node	*pop_min(t_node **queue)
{
	t_node			*current;
	t_node			*min;

	if (!queue || !*queue)
		return (NULL);
	current = *queue;
	min = *queue;
	while (current)
	{
		if (current->weight < min->weight)
			min = current;
		current = current->next;
	}
	if (*queue == min)
		*queue = min->next;
	pop(min, queue);
	return (min);
}

t_node	*new_node(t_array *a, t_array *b, char *instr, int n_instr)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	new->parent = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->child = NULL;
	new->descendants = 0;
	new->instr = instr;
	new->n_instr = n_instr;
	new->a = a;
	new->b = b;
	get_state_score(new);
	return (new);
}
