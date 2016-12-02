
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "./libft.h"
//# define ft_putchar(c) (write(1, c + '0', 1))

int		ft_printf(const char *format, ...);
/*      STATIC FUNCTIONS   */
char	*ft_itoa_int(unsigned int value, int base);
char	*ft_itoa_long(unsigned long value, int base);
int     ft_unsigned_hex(unsigned int value, char c);
int     ft_unsigned_int(unsigned int value);
int     ft_unsigned_octal(unsigned int value);
int     ft_print_address(unsigned long value);
#endif
