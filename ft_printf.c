#include "pipex.h"

static int	ft_print(int fd, const char prnt, va_list args);

int	ft_printf(int fd, const char *prnt, ...)
{
	va_list		args;
	ssize_t		total;
	int			tmp;

	if (!prnt)
		return (0);
	va_start(args, prnt);
	total = 0;
	while (*prnt)
	{
		if (*prnt == '%' && *(prnt + 1))
        {
			tmp = ft_print(fd, *++prnt, args);
            prnt++;
        }
		else
			tmp = ft_putchar_fd(*prnt++, fd);
		if (tmp < 0)
			return (-1);
		total += tmp;
	}
	va_end(args);
	return ((int)total);
}

static int	ft_print(int fd, const char prnt, va_list args)
{
	if (prnt == 'd' || prnt == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	if (prnt == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), fd));
	if (prnt == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	if (prnt == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}