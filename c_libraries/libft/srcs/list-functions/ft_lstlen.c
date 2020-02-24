/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/09 14:10:42 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/09 14:15:35 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_lstlen(t_list **alst)
{
	int		len;
	t_list	*current;

	if (alst == NULL || *alst == NULL)
		return (0);
	current = *alst;
	len = 1;
	while (current->next != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}
