/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 17:14:39 by tide-jon       #+#    #+#                */
/*   Updated: 2019/03/30 17:30:19 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	current = *alst;
	while (current && current->next)
		current = current->next;
	current->next = new;
	new->next = NULL;
}
