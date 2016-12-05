
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <wchar.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft.h"
//# define ft_putchar(c) (write(1, c + '0', 1))

int		ft_printf(const char *format, ...);
/*      STATIC FUNCTIONS   */
char    ft_to_hex(char *buf, int len, int flag);
int     ft_unsigned_hex(unsigned int value, char c);
int     ft_unsigned_int(unsigned int value);
int     ft_unsigned_octal(unsigned int value);
int     ft_print_address(unsigned long value);
int     ft_wide_string(wchar_t *s);
int     ft_wide_char(wint_t ch);
#endif
