#include <unistd.h>

struct		s_tack
{
	int		*stack;
	int		length;
}			t_tack;

int		check_if_int(char *s)
{
	if (*s == '-')
		s++;
	else if (*s == '+')
		s++;
	if ('0' <= *s && *s <= '9')
	{
		while ('0' <= *s && *s <= '9')
			s++;
		if (*s == '\0')
			return (1);
	}
	return (0);
}

int		make_stack(int argc, char *argv, struct s_tack stk)
{
	int i;

	stk.stack = (int*)malloc(sizeof(int) * (argc - 1));
	stk.length = argc - 1;
	i = 1;
	while(i < argc)
	{
		if (check_if_int(argv[i]) == 0)
			return (0);
		stk.stack[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

int		operations(struct s_tack stk_one, struct s_tack stk_two)
{

}

int		main(int argc, char *argv)
{
	struct s_tack	stk_one;
	struct s_tack	stk_two;

	if (argc <= 1)
		return (1);
	if (make_stack(argc, argv, stk_one) == 0)
	{
		write(1, "improper input\n", 15);
		return (1);
	}
	stk_two.stack = (int*)malloc(sizeof(int) * (stk_one.length - 1));
	stk_two.length = 0;
	if (operations(stk_one, stk_two) == -1)
		write(1, "ERROR\n", 6);
	else if (check_stacks(stk_one, stk_two) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}
