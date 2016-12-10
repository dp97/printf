
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <wchar.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

# define PAD_RIGHT	1
# define PLUS_SIGN	2
# define HH_FLAG	4
# define H_FLAG		8
# define LL_FLAG	16
# define L_FLAG		32
# define INTMAX_T	64
# define SIZE_T		128
# define ALT_FORM	256
# define SHOW_SIGN	512

int		ft_printf(const char *format, ...);
/*      STATIC FUNCTIONS   */
char	*ft_itoa_base(char *buf, unsigned long long value, unsigned int base, int up_low);

int     ft_unsigned(unsigned long long value, char c, int width, int flag);
int     ft_DOU(long value, char c);

int     ft_wide_string(wchar_t *s);
int     ft_wide_char(wint_t ch);

int  ft_prints(char *s, int wh, int pad);
#endif
