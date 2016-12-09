#include "ft_printf.h"

static int  ft_flags(char c, int *flags)
{
    if (c == 'h')
    {
        if (*flags & H_FLAG)
            *flags |= HH_FLAG;
        *flags |= H_FLAG;
    }
    else if (c == 'l')
    {
        if (*flags & L_FLAG)
            *flags |= LL_FLAG;
        *flags |= L_FLAG;
    }
    else if (c == 'j')
        *flags |= INTMAX_T;
    else if (c == 'z')
        *flags |= SIZE_T;
    else
        return (0);
    return (1);
}

static int	print(const char *format, va_list args)
{
	int		count;
    int     width;
    int     flag;
    int     nb;

    width = 0;
    flag = 0;
	count = 0;
	while(*format)
	{
		if (*format == '%')
		{
			format++;
            if (*format == '%')
                ft_putchar('%');
            else if (*format == '\0')
                break ;
            /*         FLAGS    # 0 + -  4/4   */
            if (*format == '#')
                ;
            else if (*format == '-')
            {
                format++;
                flag = PAD_RIGHT;
            }
            while (*format >= '0' && *format <= '9')
            {
                width *= 10;
                width += *format - '0';
                format++;
            }
            if (*format == '+')
            {
                flag = PLUS_SIGN;
                format++;
            }
            /*      FLAGS :     hh, h, l, ll, j, z */
            if (ft_flags(*format, &flag))
                format++;
            /*      CONVERSIONS      sS di cC xX u o p  14/14  D O U*/
            if (*format == 's')
            {
				char *s = va_arg(args, char *);
                count += ft_prints((s ? s : "(null)"), width, flag);
            }
			else if (*format == 'd' || *format == 'i')
            {
                nb = va_arg(args, int);
                if (nb < 0)
                    ft_putnbr(nb);
                else
                    count += ft_unsigned(nb, *format, width, flag);
            }
            else if (*format == 'u')
            {
                nb = (flag & SIZE_T) ? va_arg(args, size_t) :
                va_arg(args, unsigned int);
                count += ft_unsigned(nb, *format, width, flag);
            }
            else if (*format == 'x' || *format == 'X' || *format == 'p' || *format == 'o')
                count += ft_unsigned(va_arg(args, unsigned int), *format, width, flag);
            else if (*format == 'c')
                ft_putchar(va_arg(args, int));
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
