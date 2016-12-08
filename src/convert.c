/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:23:30 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/02 14:23:33 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#define SI(a) ((a < 0) ? -(a) : (a))

void	convert(int v, char *ans, int b, int *p)
{
    char	base[] = "0123456789ABCDEF";
    
    if (v <= -b || b <= v)
        convert(v / b, ans, b, p);
    ans[(*p)++] = base[SI(v % b)];
}

char	*ft_itoa_base(char *buf, int value, int base, int up_low)
{
    int		p;
    
    if (base < 2 || 16 < base)
        return (NULL);
    p = 0;
    if (value < 0 && base == 10)
        buf[p++] = '-';
    convert(value, buf, base, &p);
    buf[p] = '\0';
    return ((up_low) ? buf : ft_str_case(buf, 0));
}

void	convert_long(long v, char *ans, int b, int *p)
{
    char	base[] = "0123456789ABCDEF";
    
    if (v <= -b || b <= v)
        convert_long(v / b, ans, b, p);
    ans[(*p)++] = base[SI(v % b)];
}

char    *ft_itoa_long(char *buf, long value, int base, int up_low)
{
    int		p;
    
    if (base < 2 || 16 < base)
        return (NULL);
    p = 0;
    if (value < 0 && base == 10)
        buf[p++] = '-';
    convert_long(value, buf, base, &p);
    buf[p] = '\0';
    return ((up_low) ? buf : ft_str_case(buf, 0));
}