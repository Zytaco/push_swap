
#include <unistd.h>

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	while (i < len)
	{
		if (src[i + j] != 0)
			dst[i] = src[i];
		else
		{
			dst[i] = '\0';
			j--;
		}
		i++;
	}
	return (dst);
}

char		*ft_strrcut(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*newstr;

	i = 0;
	while (s1[i])
		i++;
	len = i;
	while (i >= 0)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && s2[j])
			j++;
		if (s1[i + j] == s2[j] && s2[j + 1] == '\0')
		{
			newstr = ft_strnew(sizeof(char) * (len - (j + 1)));
			ft_strncpy(newstr, s1, (size_t)(i + 1));
			ft_strncpy(newstr, s1 + i + (j + 1), (size_t)(len - (i + j + 1)));
			return (newstr);
		}
		i--;
	}
	return (s1);
}
