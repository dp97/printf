#include "ft_printf.h"
#include <stdlib.h>

static int	print(const char *format, va_list args)
{
	int		count;

	count = 0;
	while(*format)
	{
		//some_type arg = va_arg(args, some_type);
		if (*format == '%')
		{
			format++;
            if (*format == '%')
                ft_putchar('%');
            /*         FLAGS         */
            /*      CONVERSIONS      s di c xX u o p  9/14*/
			else if (*format == 's')
				ft_putstr(va_arg(args, char*));
			else if (*format == 'd' || *format == 'i')
                ft_putnbr(va_arg(args, int));
            else if (*format == 'c')
                ft_putchar(va_arg(args, int));
            else if (*format == 'x' || *format == 'X')
                count += ft_unsigned_hex(va_arg(args, unsigned int), *format);
            else if (*format == 'u')
                count += ft_unsigned_int(va_arg(args, unsigned int));
            else if (*format == 'o')
                count += ft_unsigned_octal(va_arg(args, unsigned int));
            else if (*format == 'p')
                count += ft_print_address(va_arg(args, unsigned long));
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
