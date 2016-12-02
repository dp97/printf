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

/*  CONVERT : DECIMAL -> HEX      */
int     ft_unsigned_hex(unsigned int value, char c)
{
    char    *num;
    
    num = ft_itoa_int(value, 16);
    if (c == 'x')
    {
        while (*num)
        {
            if (*num >= 'A' && *num <= 'Z')
                (*num) += 32;
            ft_putchar(*num);
            num++;
        }
    }
    else
        ft_putstr(num);
    return (ft_strlen(num));
}

/*  CONVERT : DECIMAL -> HEX      */
int     ft_unsigned_octal(unsigned int value)
{
    char    *num;
    
    num = ft_itoa_int(value, 8);
    ft_putstr(num);
    return (strlen(num));
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
    p = ft_itoa_long(value, 16);
    ft_putstr(p);
    return (ret);
}
