#include "ft_printf.h"
#include <stdlib.h>

static int	print(const char *format, va_list args)
{
	int		count;

	count = 0;
	while(*format)
	{
		//some_type arg = va_arg(listPointer, some_type);
		if (*format == '%')
		{
			ft_putchar("-");
			exit(1);
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