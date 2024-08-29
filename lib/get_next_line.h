#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

# ifdef BUFFER_SIZE 
#  if BUFFER_SIZE > 2147483647
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 2147483647
#  endif
#  if BUFFER_SIZE <= 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 1
#  endif
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct t_list
{
	char			*leftower;
	int				fd;
	long			i;
	struct t_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*ft_gnlstrjoin(char *s1, char *s2, int size);
size_t	ft_strlencpy(char *str, int mode, const char *src, size_t size);
char	*ft_gnlstrchr(const char *str, int c);
t_list	*finder(t_list **lst, int fd, size_t size);
char	*helper(t_list **temp, size_t size, char *line);
void	*ft_gnlcalloc(int size);
void	lst_clear(t_list *list);
void	line_filler(t_list **temp, int fd, char *buffer, char **line);

#endif
