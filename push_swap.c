
#include <unistd.h>
#include "push_swap.h"

/*
** level starts at 0 and solver only checks.
** then it's 1 and solver checks, does one level of operations 
*/
/*
** sa	switch top elements of a
** sb	switch top elements of b
** ss	sa and sb
** pa	move top of b to top of a
** pb	move top of b to top of a
** ra	first of a becomes last and other elements shift
** rb	first of b becomes last and other elements shift
** rr	ra and rb
** rra	last of a becomes first and other elements shift
** rrb	last of b becomes first and other elements shift
** rrr	rra and rrb
*/

char		*remove_operation(char *solution, int i)
{
	char *new;

	if (i == 0)
		new = ft_strcut(solution, "sa\n");
	else if (i == 1)
		new = ft_strcut(solution, "sb\n");
	else if (i == 2)
		new = ft_strcut(solution, "ss\n");
	else if (i == 3)
		new = ft_strcut(solution, "pa\n");
	else if (i == 4)
		new = ft_strcut(solution, "pb\n");
	else if (i == 5)
		new = ft_strcut(solution, "ra\n");
	else if (i == 6)
		new = ft_strcut(solution, "rb\n");
	else if (i == 7)
		new = ft_strcut(solution, "rr\n");
	else if (i == 8)
		new = ft_strcut(solution, "rra\n");
	else if (i == 9)
		new = ft_strcut(solution, "rrb\n");
	else if (i == 10)
		new = ft_strcut(solution, "rrr\n");
	free(solution);
	solution = NULL;
	return (new);
}

char		*add_operation(char *solution, int i)
{
	char *new;

	if (i == 0)
		new = ft_strjoin(solution, "sa\n");
	else if (i == 1)
		new = ft_strjoin(solution, "sb\n");
	else if (i == 2)
		new = ft_strjoin(solution, "ss\n");
	else if (i == 3)
		new = ft_strjoin(solution, "pa\n");
	else if (i == 4)
		new = ft_strjoin(solution, "pb\n");
	else if (i == 5)
		new = ft_strjoin(solution, "ra\n");
	else if (i == 6)
		new = ft_strjoin(solution, "rb\n");
	else if (i == 7)
		new = ft_strjoin(solution, "rr\n");
	else if (i == 8)
		new = ft_strjoin(solution, "rra\n");
	else if (i == 9)
		new = ft_strjoin(solution, "rrb\n");
	else if (i == 10)
		new = ft_strjoin(solution, "rrr\n");
	free(solution);
	solution = NULL;
	return (new);
}

int			solver(t_tack a, t_tack b, char *solution, int level)
{
	int i;

	if (level == 0 && checks(a, b) == 1)
		return (1);
	if (level > 0)
	{
		i = 0;
		while (i < 11)
		{
			do_operation(a, b, i);
			solution = add_operation(solution, i);
			if (solver(a, b, solution, level - 1) == 1)
				return (1);
			undo_operation(a, b, i);
			solution = remove_operation(solution, i);
			i++;
		}
	}
	return (0);
}

int			make_stack(int argc, char **argv, t_tack *stk_one, t_tack *stk_two)
{
	int i;

	stk_two->length = 0;
	stk_two->stack = (int*)malloc(sizeof(int) * (argc - 1));
	stk_one->stack = (int*)malloc(sizeof(int) * (argc - 1));
	if (stk_one->stack == NULL && stk_two->stack == NULL)
		return (-1);
	stk_one->length = argc - 1;
	i = 1;
	while (i < argc)
	{
		if (check_if_int(argv[i]) == 0)
			return (0);
		stk_one->stack[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	struct s_tack	stk_one;
	struct s_tack	stk_two;
	char			*solution;
	int				level;

	solution = NULL;
	if (argc <= 1)
		return (1);
	if (make_stack(argc, argv, &stk_one, &stk_two) == 0)
	{
		write(1, "improper input\n", 15);
		return (1);
	}
	level = 0;
	while (solver(stk_one, stk_two, &solution, level) == 0)
		level++;
	write_solution(&solution);
	free(stk_one.stack);
	free(stk_two.stack);
	return (1);
}
