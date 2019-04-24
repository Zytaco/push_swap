
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_tack
{
	int			*stack;
	int			length;
}				t_tack;
int				check_if_int(char *s);
void			operate(char *line, struct s_tack a, struct s_tack b);
void			operate_helper(char *line, struct s_tack a, struct s_tack b);
int				ft_atoi(const char *str);

#endif
