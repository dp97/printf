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
static int  ft_len(unsigned int nb)
{
    unsigned int    tmp;
    int             len;
    
    tmp = nb;
    len = 0;
    while (tmp != 0)
    {
        tmp /= 10;
        len++;
    }
    return (len);
}

int     ft_unsigned_hex(unsigned int value, char c)
{
    char    *buf;
    int     flag;
    int     len;
    
    flag = 0;
    len = ft_len(value);
    if ((buf = (char *)malloc(sizeof(char) * (11))) == NULL)
        return (0);
    if (c == 'X')
        flag = 1;
    if (c == 'o')
        buf = ft_to_hex(buf, value, len+1, flag, 8);
    else
        buf = ft_to_hex(buf, value, len, flag, 16);
    ft_putstr(buf);
    return (1);
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

/*  PRINT   : ADDRESS OF A VOID POINTER       */
int     ft_print_address(unsigned long value)
{
    int     ret;
    char    *p;
    
    ft_putstr("0x");
    ft_putstr(ft_to_hex(p, value, 10, 0, 16));
    return (ret);
}
