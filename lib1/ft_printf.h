#ifndef FT_PRINTF_H
# define FT_PRINTF_H 
# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *bruh, ...);
char	*hex(unsigned int i, int base);
char	*pointer(unsigned long i);
char	*uitoa(long long i);

#endif