#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>

struct		s_tack
{
	int		*stack;
	int		length;
}			t_tack;
int			check_if_int(char *s);
void		operate(char *line, struct s_tack a, struct s_tack b);
void		operate_helper(char *line, struct s_tack a, struct s_tack b);

#endif
