/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 14:01:08 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:10:57 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
