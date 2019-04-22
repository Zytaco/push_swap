
#include "checker.h"

static void	reverse_rotate(struct s_tack stk)
{
	int temp;
	int i;

	temp = stk.stack[stk.length - 1];
	i = 0;
	while (i < stk.length - 1)
	{
		stk.stack[i] = stk.stack[i + 1];
		i++;
	}
	stk.stack[0] = temp;
}

void	operate_helper(char *line, struct s_tack a, struct s_tack b)
{
	if (strcmp(line, "rr"))
	{
		rotate(a);
		rotate(b);
	}
	else if (strcmp(line, "rra"))
		reverse_rotate(a);
	else if (strcmp(line, "rrb"))
		reverse_rotate(b);
	else if (strcmp(line, "rrr"))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		write(1, "ERROR1\n", 7);
}
