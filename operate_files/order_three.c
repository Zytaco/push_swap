/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   order_three.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 16:15:55 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/06/07 16:15:56 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "order_three.h"

void		order_three_a(int *stk, t_tack *a, t_tack *b, t_word *start)
{
	int low;
	int big;

	low = find_lowest(stk, 3);
	big = find_biggest(stk, 3);
	if (stk[0] != low && stk[1] != big)
		do_thing_a("sa.", start, a, b);
	if (stk[2] == big)
		return ;
	do_thing_a("ra.", start, a, b);
	do_thing_a("sa.", start, a, b);
	do_thing_a("rra", start, a, b);
	if (stk[0] != low)
		do_thing_a("sa.", start, a, b);
}

void		order_three_b(int *stk, t_tack *a, t_tack *b, t_word *start)
{
	int low;
	int big;

	low = find_lowest(stk, 3);
	big = find_bigest(stk, 3);
	if (stk[0] != low && stk[1] != big)
		do_thing_b("sb.", start, a, b);
	if (stk[2] == big)
		return ;
	do_thing_b("rb.", start, a, b);	
	do_thing_b("sb.", start, a, b);	
	do_thing_b("rrb", start, a, b);	
	if (stk[0] != low)
		do_thing_b("sb.", start, a, b);
}
