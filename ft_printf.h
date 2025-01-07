#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int     ft_printf(int fd, const char *prnt, ...);

ssize_t ft_putchar_fd(const char prnt, int fd);
ssize_t ft_putstr_fd(char *s, int fd);
ssize_t ft_putnbr_fd(long num, int fd);


#endif