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

int     ft_to_hex(char *buf, unsigned int u, int len, int flag, int base)
{
    int     pos;
    char    *table;
    char	b_up[] = "0123456789ABCDEF";
    char	b_low[] = "0123456789abcdef";
    int     count;
    
    count = 0;
    pos = len;
    if (flag == 1)
        table = b_up;
    else
        table = b_low;
    buf[--pos] = '\0';
    while (u != 0)
    {
        buf[pos--] = table[u % base];
        u /= base;
        count++;
    }
    return (count);
}