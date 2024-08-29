#include "ft_printf.h"

static int	localsymb(unsigned long n)
{
	int	res;

	res = 0;
	while (n != 0)
	{
		n /= 16;
		res++;
	}
	return (res);
}

static char	*localfill(unsigned long n, char *res, int symb, char *base)
{
	res[symb] = 0;
	while ((symb - 1) >= 0 && n != 0)
	{
		res[symb - 1] = base[n % 16];
		n /= 16;
		symb--;
	}
	if (symb == 1)
		res[0] = '-';
	return (res);
}

static char	*uhex(unsigned long i, int base)
{
	char	a[17];
	char	*ret;
	int		symb;

	if (base != 'X')
		ft_strlcpy(a, "0123456789abcdef", 17);
	else
		ft_strlcpy(a, "0123456789ABCDEF", 17);
	symb = localsymb(i);
	ret = ft_calloc((symb + 1), sizeof(char));
	if (!ret)
		return (NULL);
	ret = localfill(i, ret, symb, a);
	return (ret);
}

char	*hex(unsigned int i, int base)
{
	char	a[17];
	char	*ret;
	int		symb;

	if (i == 0)
	{
		ret = ft_calloc(2, sizeof(char));
		if (!ret)
			return (NULL);
		ret[0] = '0';
		return (ret);
	}
	if (base != 'X')
		ft_strlcpy(a, "0123456789abcdef", 17);
	else
		ft_strlcpy(a, "0123456789ABCDEF", 17);
	symb = localsymb(i);
	if (i < 0)
		symb++;
	ret = ft_calloc((symb + 1), sizeof(char));
	if (!ret)
		return (NULL);
	ret = localfill(i, ret, symb, a);
	return (ret);
}

char	*pointer(unsigned long i)
{
	char	*res;
	char	*bruh;
	char	*bruh2;

	if (i == 0)
	{
		bruh = ft_calloc(6, 1);
		if (!bruh)
			return (NULL);
		ft_strlcpy(bruh, "(nil)", 6);
		return (bruh);
	}
	bruh = ft_calloc(3, sizeof(char));
	if (!bruh)
		return (NULL);
	bruh2 = uhex(i, 'p');
	if (!bruh2)
		return (free (bruh), NULL);
	ft_strlcpy(bruh, "0x", 3);
	res = ft_strjoin(bruh, bruh2);
	return (free(bruh2), res);
}
