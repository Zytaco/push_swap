/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 12:43:38 by jheeresm      #+#    #+#                 */
/*   Updated: 2020/01/08 12:43:38 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "srcs/ft_printf/ft_printf.h"
#include <math.h>

int		main(void)
{
	int a;
	int bbbb;
	L double	c;
	long double		inputs[14] = {-0., 0., 1., 2., 3., 4., 5., 6., 7., 8.,
	INFINITY, -INFINITY, NAN, -NAN};
	int				i;

	i = 0;
	while (i < 14)
	{
		a = ft_printf("%d: %Lf\n", i, inputs[i]);
		bbbb = printf("%d: %Lf\n", i, inputs[i]);
		if (a != bbbb)
			printf("ERROR: returns from ft_printf and printf don't match\n");
		else
			ft_printf("\n");
		i++;
	}
}
