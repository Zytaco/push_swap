/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jheeresm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 16:09:38 by jheeresm      #+#    #+#                 */
/*   Updated: 2019/02/11 12:17:42 by jheeresm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int i;

	if (s == (char*)0 || f == (void*)0)
		return ;
	i = 0;
	while (s[i])
	{
		f(s + i);
		i++;
	}
}
