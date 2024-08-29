#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		ft_putstr_fd("(null)", 1);
	else
	{
		while (*s)
		{
			write(fd, s, sizeof(char));
			s++;
		}
	}
}
