#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <bsd/string.h>
# include <fcntl.h>
//isfuncs
int		ft_isdigit(int x);

// //strfuncs0
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*search(char const *s, char c);

// //strfuncs1
void	ft_bzero(void *s, size_t n);

// //leftovers
void	*ft_calloc(size_t nitems, size_t size);

// //additionals
char	*ft_strjoin(char *s1, char const *s2);

char	*ft_itoa(int n);

// //files
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strtrim(char *s1, char const *set);
char	*ft_substr(char *s, unsigned int start, size_t len);

char	*get_next_line(int fd);
char	*ft_gnlstrjoin(char *s1, char *s2, int size);
char	*ft_frstrtrim(char *s1, char const *set);

#endif

//kind of fun, kind of cool, kind of awesome