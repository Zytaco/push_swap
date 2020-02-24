/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 17:38:47 by tide-jon       #+#    #+#                */
/*   Updated: 2019/10/04 15:34:19 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <float.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"

# define LL long long
# define ULL unsigned long long
# define L long
# define UL unsigned long
# define U unsigned

typedef struct		s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}					t_list;

typedef struct		s_gnl_list
{
	int					fd;
	char				*content;
	struct s_gnl_list	*next;
}					t_gnl_list;

/*
** char-functions
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isint(char *s, int len);
int					ft_isprint(int c);
int					ft_iswhitespace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** ft_libft
*/
int					ft_printf(const char *format, ...);

/*
** list-functions
*/
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstaddlast(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
int					ft_lstlen(t_list **alst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
** math-functions
*/
int					ft_abs(int num);
LL					ft_bcd(LL a, LL b);
int					ft_count_digits(LL n);
LL					ft_lcm(LL a, LL b);
LL					ft_max(LL a, LL b);
LL					ft_min(LL a, LL b);
int					ft_modulo(int x, int mod);
int					ft_nroot(unsigned int num, unsigned int degree);
LL					ft_power(int num, int power);
int					ft_isprime(int n);
int					ft_get_next_prime(int n);
int					ft_pythagoras(int x, int y);
int					ft_sqrt(unsigned int num);

/*
** mem-functions
*/
void				ft_bzero(void *s, size_t n);
void				ft_free(void *ptr);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *rc, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

/*
** misc-functions
*/
int					ft_atoi(const char *str);
ULL					ft_atoullbase(const char *s, int base);
void				ft_error(char *str);
void				ft_free_array(void ***array);
int					ft_get_next_line(const int fd, char **line);
char				*ft_itoa(LL n);
char				*ft_utoa(ULL n);
char				*ft_itobase(LL n, int base);
char				*ft_utobase(ULL n, int base);

/*
** put-functions
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(LL n, int fd);
void				ft_putnbr(LL n);
void				ft_putnbrbase_fd(LL n, int base, int fd);
void				ft_putnbrbase(LL n, int base);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putunbr_fd(ULL n, int fd);
void				ft_putunbr(ULL n);
void				ft_putunbrbase_fd(ULL n, int base, int fd);
void				ft_putunbrbase(ULL n, int base);

/*
** standard-queue
*/


/*
** str-functions
*/
int					ft_skip_whitespace(const char *str);
int					ft_skipstr(const char *str, const char *skip);
int					ft_skipnstr(const char *str, const char *skip);
void				ft_stradd(const char **replace, const char *add);
char				*ft_strapp(char **s, const char *app);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strcount(const char *s, char c);
int					ft_strcount_whitespace(const char *s);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
char				**ft_strfsplit(char const *s, int (*split)(int));
char				*ft_strins(char **s, const char *ins, int i);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
void				ft_strlower(char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strndup(const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack, const char *needle,
																size_t len);
char				*ft_strprep(const char *pre, char **s);
char				*ft_strrchr(char *s, int c);
char				*ft_strrepeat(const char *s, ULL n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtoupper(char *str);
char				*ft_strtrim(char const *s);
void				ft_strupper(char *s);

#endif
