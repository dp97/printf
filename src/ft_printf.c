/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 18:21:35 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/10 18:24:36 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_flags_2(char c, int *flags)
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

static const char  *ft_flags_1(const char *format,int *flag, int *width)
{
    if (*format == '#')
    {
        *flag |= ALT_FORM;
        format++;
    }
    if (*format == '-')
    {
        format++;
        *flag |= PAD_RIGHT;
    }
    while (*format >= '0' && *format <= '9')
    {
        *width *= 10;
        *width += (*format) - '0';
        format++;
    }
    if (*format == '+')
    {
        *flag |= PLUS_SIGN;
        format++;
    }
    return (format);
}

static int	print(const char *format, va_list args)
{
    unsigned long long     nb;
    char *s;
    char ch;
	int		count;
    int     width;
    int     flag;

    width = 0;
	count = 0;
    nb = 0;
	while(*format)
	{
        flag = 0;
		if (*format == '%')
		{
			format++;
            if (*format == '%')
                ft_putchar('%');
            else if (*format == '\0')
                break ;
            /*         FLAGS    # 0 + -  4/4   */
            format = ft_flags_1(format, &flag, &width);
            /*      FLAGS :     hh, h, l, ll, j, z */
            if (ft_flags_2(*format, &flag))
                format++;
            /*      CONVERSIONS      sS di cC xX u o p  14/14  D O U*/
            if (*format == 's' || *format == 'S')
            {
                if (*format == 'S')
                    flag |= L_FLAG;
                s = va_arg(args, char *);
                
                count += ft_prints((s ? s : "(null)"), width, flag);
            }
            else if (*format == 'c' || *format == 'C')
            {
                if (*format == 'C')
                    flag |= L_FLAG;
                ch = (flag & L_FLAG) ? (wint_t)va_arg(args, int) :
                (va_arg(args, int));
                
                ft_putchar(ch);
            }
			else if (*format == 'd' || *format == 'i' || *format == 'D')
            {
                if (*format == 'D')
                    flag |= L_FLAG;
                nb = (flag & H_FLAG) ? (short)va_arg(args, int) :
                (flag & HH_FLAG) ? (signed char)va_arg(args, int) :
                (flag & L_FLAG) ? va_arg(args, long) :
                (flag & LL_FLAG) ? va_arg(args, long long) :
                (flag & INTMAX_T) ? va_arg(args, intmax_t) :
                (flag & SIZE_T) ? va_arg(args, ssize_t) :
                va_arg(args, int);
                
                flag |= SHOW_SIGN;
                count += ft_unsigned(nb, *format, width, flag);
            }
            else if (*format == 'u' || *format == 'U')
            {
                if (*format == 'U')
                    flag |= L_FLAG;
                nb = (flag & H_FLAG) ? (unsigned short)va_arg(args, unsigned int) :
                (flag & HH_FLAG) ? (unsigned char)va_arg(args, unsigned int) :
                (flag & L_FLAG) ? va_arg(args, unsigned long) :
                (flag & LL_FLAG) ? va_arg(args, unsigned long long) :
                (flag & INTMAX_T) ? va_arg(args, uintmax_t) :
                (flag & SIZE_T) ? va_arg(args, size_t) :
                va_arg(args, unsigned int);
                
                count += ft_unsigned(nb, *format, width, flag);
            }
            else if (*format == 'o' || *format == 'O')
            {
                if (*format == 'O')
					flag |= L_FLAG;
                nb = (flag & H_FLAG) ? (unsigned short)va_arg(args, unsigned int) : \
					 (flag & HH_FLAG) ? (unsigned char)va_arg(args, unsigned int) : \
					 (flag & L_FLAG) ? va_arg(args, unsigned long) : \
					 (flag & LL_FLAG) ? va_arg(args, unsigned long long) : \
					 (flag & INTMAX_T) ? va_arg(args, uintmax_t) : \
					 (flag & SIZE_T) ? va_arg(args, size_t) : \
					 va_arg(args, unsigned int);
                
                count += ft_unsigned(nb, *format, width, flag);
            }
            else if (*format == 'x' || *format == 'X')
            {
                nb = (flag & H_FLAG) ? (unsigned short)va_arg(args, unsigned int) :
                (flag & HH_FLAG) ? (unsigned char)va_arg(args, unsigned int) :
                (flag & L_FLAG) ? va_arg(args, unsigned long) :
                (flag & LL_FLAG) ? va_arg(args, unsigned long long) :
                (flag & INTMAX_T) ? va_arg(args, uintmax_t) :
                (flag & SIZE_T) ? va_arg(args, size_t) :
                va_arg(args, unsigned int);
                
                count += ft_unsigned(nb, *format, width, flag);
            }
            else if (*format == 'p')
            {
            }
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
