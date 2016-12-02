
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "./libft.h"
# define ft_putchar(c) (write(1, &c, 1))

int		ft_printf(const char *format, ...);
#endif
