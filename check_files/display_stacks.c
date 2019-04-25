
#include <stdio.h>
#include "checker_main.h"

void	display_stacks(t_tack a, t_tack b)
{
	int i;

	printf("a, length %d\n", a.length);
	i = 0;
	while (i < a.length)
	{
		printf("%d\n", a.stack[i]);
		i++;
	}
	printf("b, length %d\n", b.length);
	i = 0;
	while (i < b.length)
	{
		printf("%d\n", b.stack[i]);
		i++;
	}
}
