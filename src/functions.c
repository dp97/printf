/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:45:26 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/14 16:39:35 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*  PRINT :  wide char string      */
int     ft_wide_string(wchar_t *s)
{
    int             i;
    unsigned char   *ch;
    
    i = 0;
    while (s[i])
    {
        ch = (unsigned char*) & s[i];
        ft_putc(ch[0]);
        i++;
    }
    return (i);
}

/*  PRINT :  wide char           */
int     ft_wide_char(wint_t ch)
{
    unsigned char   *c;
    
    c = (unsigned char*) & ch;
    ft_putc(c[0]);
    return (1);
}

/*  CONVERT : DECIMAL -> HEX      */
int  ft_prints(char *s, int wh, int pad)
{
    int     count;
    
    count = ft_len(s);
    if (pad)
        ft_puts(s);
    while (wh > count)
    {
        ft_putc(' ');
        count++;
    }
    if (!pad)
        ft_puts(s);
    return (count);
}

int     ft_unsigned(unsigned long long value, char c, int width, int flag)
{
    char	*buf;
    int     len;
    
    len = 0;
    if ((buf = (char *)malloc(sizeof(char) * 32)) == NULL)
        return (0);
    if (c == 'X')
    {
        if (flag & ALT_FORM)
        {
            ft_puts("0X");
            len += 2;
        }
        buf = ft_itoa_base(buf, value, 16, 1);
    }
    else if (c == 'x')
    {
        if (flag & ALT_FORM)
        {
            ft_puts("0x");
            len += 2;
        }
        buf = ft_itoa_base(buf, value, 16, 0);
    }
    else if (c == 'o')
    {
        if (flag & ALT_FORM)
        {
            ft_puts("0");
            len += 1;
        }
        buf = ft_itoa_base(buf, value, 8, 0);
    }
    else if (c == 'u')
        buf = ft_itoa_base(buf, value, 10, 0);
    else if (c == 'p')
    {
        ft_puts("0x");
        len += 2;
        buf = ft_itoa_base(buf, value, 16, 0);
    }
    else if (c == 'i' || c == 'd')
    {
        if ((flag & SHOW_SIGN) && (long long)value < 0)
        {
            ft_puts("-");
            value = -value;
            len++;
        }
        buf = ft_itoa_base(buf, value, 10, 0);
    }
    if (flag & PLUS_SIGN)
    {
        ft_putc('+');
        len++;
    }
    len += ft_prints(buf, width, flag);
    free(buf);
    return (len);
}

int     ft_DOU(long value, char c)
{
    char	*buf;
    int     len;
    
    len = 0;
    if ((buf = (char *)malloc(sizeof(char) * 35)) == NULL)
        return (0);
    if (c == 'D')
        buf = ft_itoa_base(buf, value, 10, 0);
    else if (c == 'O')
        buf = ft_itoa_base(buf, value, 8, 0);
    else if (c == 'U')
        buf = ft_itoa_base(buf, value, 10, 0);
    ft_puts(buf);
    len = ft_len(buf);
    free(buf);
    return (len);
}
