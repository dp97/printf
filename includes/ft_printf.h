
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <wchar.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
// 1,2,4,8,16,32,64,128
# define PAD_RIGHT  1
# define PLUS_SIGN  2
# define HH_FLAG 4
# define H_FLAG  8
# define LL_FLAG  16
# define L_FLAG  32
# define INTMAX_T    64
# define SIZE_T  128

int		ft_printf(const char *format, ...);
/*      STATIC FUNCTIONS   */
char	*ft_itoa_base(char *buf, unsigned long long value, unsigned int base, int up_low);
char    *ft_itoa_long(char *buf, long value, int base, int up_low);

int     ft_unsigned(unsigned long long value, char c, int width, int flag);
int     ft_DOU(long value, char c);

int     ft_wide_string(wchar_t *s);
int     ft_wide_char(wint_t ch);

int  ft_prints(char *s, int wh, int pad);
#endif
