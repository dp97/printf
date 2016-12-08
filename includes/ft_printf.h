
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <wchar.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *format, ...);
/*      STATIC FUNCTIONS   */
char	*ft_itoa_base(char *buf, int value, int base, int up_low);
char    *ft_itoa_long(char *buf, long value, int base, int up_low);

int     ft_unsigned_hex(unsigned int value, char c);
int     ft_DOU(long value, char c);

int     ft_unsigned_int(unsigned int value);
int     ft_wide_string(wchar_t *s);
int     ft_wide_char(wint_t ch);
#endif
