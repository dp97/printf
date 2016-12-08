#include "ft_printf.h"
#include <stdlib.h>

static int	print(const char *format, va_list args)
{
	int		count;

	count = 0;
	while(*format)
	{
		if (*format == '%')
		{
			format++;
            if (*format == '%')
                ft_putchar('%');
            else if (*format == '\0') // END OF STRING
                break ;
            /*         FLAGS         */
            /*      CONVERSIONS      sS di cC xX u o p  11/14  D O U*/
			else if (*format == 's')
				ft_putstr(va_arg(args, char*));
			else if (*format == 'd' || *format == 'i')
                ft_putnbr(va_arg(args, int));
            else if (*format == 'c')
                ft_putchar(va_arg(args, int));
            else if (*format == 'x' || *format == 'X' || *format == 'o' || *format == 'p')
                count += ft_unsigned_hex(va_arg(args, unsigned int), *format);
            else if (*format == 'u') {
                count += ft_unsigned_int(va_arg(args, unsigned int));
            }
            else if (*format == 'C') // lc
                count += ft_wide_char(va_arg(args, wint_t));
            else if (*format == 'S') // ls
                count += ft_wide_string(va_arg(args, wchar_t*));
            else if (*format == 'D' || *format == 'O' || *format == 'U') // ld ld lu
                count += ft_DOU(va_arg(args, long), *format);
		}
		else
		{
			ft_putchar(*format);
			++count;
		}
		format++;	
	}
	va_end(args);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list	listPointer;

	va_start(listPointer, format);

	int i = print(format, listPointer);
	return (i);
}
