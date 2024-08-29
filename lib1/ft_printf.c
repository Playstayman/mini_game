#include "ft_printf.h"

static int	checker(char *whatever)
{
	if (*(whatever + 1) == 0)
		return (-2);
	if (*(whatever + 2) == 0)
		return (-2);
	return (ft_putchar_fd('%', 1), 1);
}

static int	getter(char *whatever, va_list list)
{
	char	a;
	int		c;
	char	*b;

	a = *(whatever + 1);
	if (a == 's')
		return (b = va_arg(list, void *), ft_putstr_fd(b, 1), ft_strlen(b));
	else if (a == 'c')
		return (ft_putchar_fd(va_arg(list, int), 1), 1);
	else if (a == 'd' || a == 'i')
		b = ft_itoa(va_arg(list, int));
	else if (a == 'x' || a == 'X')
		b = hex(va_arg(list, unsigned int), a);
	else if (a == 'p')
		b = pointer(va_arg(list, size_t));
	else if (a == 'u')
		b = uitoa(va_arg(list, unsigned int));
	else if (a == '%')
		return (ft_putchar_fd('%', 1), 1);
	else
		return (checker(whatever));
	return (ft_putstr_fd(b, 1), c = ft_strlen(b), free (b), c);
}

static void	actual_thing(va_list list, int *res, const char *whatever)
{
	char	*bruh;
	int		a;

	bruh = (char *)whatever;
	while (*bruh && *res != -1)
	{
		if (*bruh != '%')
			(ft_putchar_fd(*bruh, 1), (*res)++);
		else
		{
			a = getter(bruh, list);
			if (a == -1)
				a += 7;
			if (a == -2)
			{
				*res = -1;
				return ;
			}
			*res += a;
			bruh++;
		}
		bruh++;
	}
}

int	ft_printf(const char *whatever, ...)
{
	va_list	list;
	int		res;

	res = 0;
	va_start(list, whatever);
	if (!ft_strchr(whatever, '%'))
		return (ft_putstr_fd((char *)whatever, 1), ft_strlen(whatever));
	else
	{
		actual_thing(list, &res, whatever);
	}
	return (res);
}

// #include "ft_printf.h"

// int main()
// {
// 	ft_printf("abc%iABC\n", ft_printf("ZXC%z", 943));
// 	printf("abc%iABC", printf("ZXC%z", 943));
// }