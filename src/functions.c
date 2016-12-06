/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:45:26 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/02 14:45:30 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*  RETURN SQUARE ROOT   */
static int  sqr(int b)
{
    int     a;
    
    a = 1;
    while (b)
    {
        a *= 10;
        b--;
    }
    return (a);
}

/*  PRINT :  wide char string      */
int     ft_wide_string(wchar_t *s)
{
    int             i;
    unsigned char   *ch;
    wchar_t         c;
    
    i = 0;
    while (s[i])
    {
        ch = (unsigned char*) & s[i];
        ft_putchar(ch[0]);
        i++;
    }
    return (i);
}

/*  PRINT :  wide char           */
int     ft_wide_char(wint_t ch)
{
    unsigned char   *c;
    
    c = (unsigned char*) & ch;
    ft_putchar(c[0]);
    return (1);
}

/*  CONVERT : DECIMAL -> HEX      */
int     ft_unsigned_hex(unsigned int value, char c)
{
    char    *buf;
    int     len;
    
    if ((buf = (char *)malloc(sizeof(char) * 11)) == NULL)
        return (0);
    if (c == 'X')
        len = ft_to_hex(buf, value, 10, 1, 16);
    else if (c == 'o')
        len = ft_to_hex(buf, value, 10, 0, 8);
    else if (c == 'p')
    {
        ft_putstr("0x");
        len = ft_to_hex(buf, value, 10, 0, 16);
    }
    else
        len = ft_to_hex(buf, value, 10, 0, 16);
    ft_putstr(buf);
    free(buf);
    return (len);
}

/*  PRINT   : UNSIGNED INT       */
int     ft_unsigned_int(unsigned int value)
{
    int             count;
    unsigned int    temp;
    int             ret;
    
    count = 1;
    ret = 0;
    temp = value;
    while (temp > 9)
    {
        temp /= 10;
        count += 1;
    }
    temp = value;
    while (count)
    {
        count--;
        ft_putchar(temp / sqr(count) + '0');
        temp = value % sqr(count);
        ret++;
    }
    return (ret);
}
