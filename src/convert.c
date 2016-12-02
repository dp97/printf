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

static void	convert_int(unsigned int v, char *ans, int b, int *p)
{
    char	base[] = "0123456789ABCDEF";
    
    if (b <= v)
        convert_int(v / b, ans, b, p);
    ans[(*p)++] = base[SI(v % b)];
}

static void	convert_long(unsigned long v, char *ans, int b, int *p)
{
    char	base[] = "0123456789abcdef";
    
    if (b <= v)
        convert_long(v / b, ans, b, p);
    ans[(*p)++] = base[SI(v % b)];
}

char	*ft_itoa_int(unsigned int value, int base)
{
    int		p;
    char	*ans;
    
    if (((ans = (char *)malloc(sizeof(char) * 100)) == NULL))
        return (NULL);
    p = 0;
    convert_int(value, ans, base, &p);
    ans[p] = '\0';
    return (ans);
}

char	*ft_itoa_long(unsigned long value, int base)
{
    int		p;
    char	*ans;
    
    if (((ans = (char *)malloc(sizeof(char) * 100)) == NULL))
        return (NULL);
    p = 0;
    convert_long(value, ans, base, &p);
    ans[p] = '\0';
    return (ans);
}