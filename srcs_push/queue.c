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

	if (!new)
		return ;
	bef = NULL;
	aft = *start;
	while (aft && new->members > aft->members)
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

int		state_match(t_node n, t_node m)
{
	int i;

	if (n.a->len != m.a->len || n.b->len != m.b->len)
		return (0);
	i = 0;
	while (i < n.a->len || i < n.b->len)
	{
		if (i < n.a->len && n.a->stack[i] != m.a->stack[i])
			return (0);
		if (i < n.b->len && n.b->stack[i] != m.b->stack[i])
			return (0);
		i++;
	}
	return (1);
}

int		dup_state(t_node *start, t_node state)
{
	while (start)
	{
		if (start->weight <= state.weight)
		{
			if (state_match(*start, state))
				return (1);
			if (start->child && dup_state(start->child, state))
				return (1);
		}
		start = start->next;
	}
	return (0);
}
