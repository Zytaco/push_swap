
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
