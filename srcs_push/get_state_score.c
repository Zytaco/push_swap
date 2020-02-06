/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_state_score.c                                   :+:    :+:           */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 11:33:57 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/11/19 11:33:57 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			rot_distance(int dist, int len)
{
	return ((len - ft_abs((2 * ft_abs(dist)) - len)) / 2);
}

