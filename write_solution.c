
#include <unistd.h>

void	write_solution(char **solution)
{
	int i;

	if (*solution == NULL)
	{
		write(1, "", 1);
		return ;
	}
	i = 0;
	while ((*solution)[i])
		i++;
	write(1, *solution, i);
	free(*solution);
	*solution = NULL;
}
