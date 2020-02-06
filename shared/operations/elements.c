/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   elements.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:24:53 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/02/05 15:24:53 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_tack		rot(t_tack st)
{
	U int	i;
	int		*const new = ft_memalloc(sizeof(int) * st.size);
	int 	temp;

	if (st.size <= 1)
		return (copy(st, 0));
	i = 0;
	temp = st.stack[0];
	while (i + 1 < st.size)
	{
		st.stack[i] = st.stack[i + 1];
		i++;
	}
	st.stack[i] = temp;
	return ((t_tack){new, st.size});
}

t_tack		rev_rot(t_tack st)
{
	U int	i;
	int		*const new = ft_memalloc(sizeof(int) * st.size);
	int		temp;

	if (st.size <= 1)
		return (copy(st, 0));
	i = st.size - 1;
	temp = st.stack[st.size - 1];
	while (i >= 1)
	{
		st.stack[i] = st.stack[i - 1]; 
		i--;
	}
	st.stack[i] = temp;
	return ((t_tack){new, st.size});
}

t_tack		swap(t_tack st)
{
	t_tack	new = copy(st, 0);

	new.stack[0] = st.stack[1];
	new.stack[1] = st.stack[0];
	return (new);
}

/*
** 1 2 3 4 5 6          offset: +1
** - 1 2 3 4 5 6
**
** 1 2 3 4 5 6          offset: -1
** 2 3 4 5 6
*/
t_tack		copy(t_tack st, int offset)
{
	U int	i;
	int		*const new = ft_memalloc(sizeof(int) * (st.size + offset));

	if (!new)
		return ((t_tack){NULL, 0});
	i = (0 < offset) ? 0 : offset;
	while (i < st.size)
	{
		new[i + offset] = st.stack[i];
		i++;
	}
	return ((t_tack){new, st.size + offset});
}
