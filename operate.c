
#include "checker.h"

static void	swap(struct s_tack stk)
{
	int temp;

	if (stk.length <= 1)
		return;
	temp = stk.stack[0];
	stk.stack[0] = stk.stack[1];
	stk.stack[1] = temp;
}

static void	push(struct s_tack a, struct s_tack b)
{
	int i;

	if (b.length <= 0)
		return ;
	i = a.length - 1;
	while (i >= 0)
	{
		a.stack[i + 1] = a.stack[i];
		i--;
	}
	a.length++;
	a.stack[0] = b.stack[0];
	i = 0;
	while (i < b.length - 1)
	{
		b.stack[i] = b.stack[i + 1];
		i++;
	}
	b.length--;
}

static void	rotate(struct s_tack stk)
{
	int temp;
	int i;

	temp = stk.stack[0];
	i = 0;
	while (i < stk.length - 1)
	{
		stk.stack[i] = stk.stack[i + 1];
		i++;
	}
	stk.stack[stk.length] = temp;
}

void		operate(char *line, struct s_tack a, struct s_tack b)
{
	if (strcmp(line, "sa"))
		swap(a);
	else if (strcmp(line, "sb"))
		swap(b);
	else if (strcmp(line, "ss"))
	{
		swap(a);
		swap(b);
	}
	else if (strcmp(line, "pa"))
		push(a, b);
	else if (strcmp(line, "pb"))
		push(b, a);
	else if (strcmp(line, "ra"))
		rotate(a);
	else if (strcmp(line, "rb"))
		rotate(b);
	else
		operate_helper(line, a, b);
}

