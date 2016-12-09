/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:09:09 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/09 14:11:04 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main()
{
    char *np = 0;
    char buf[80] = "12345";
    int     nb = -12345;
    
	ft_printf("|%d\n", ft_printf("<%zu> <%s>", sizeof(buf), np));

	printf("|%d\n", printf("<%zu> <%s>", sizeof(buf), np));
    
    
    ft_printf("just==: \"%+d\"\n", nb);
    printf("justif: \"%+d\"\n", nb);
    
    
    
    
    ft_printf("just==: \"%-3s\"\n", "left");
    printf("justif: \"%-3s\"\n", "left");
    ft_printf("just==: \"%6s\"\n", "right");
    printf("justif: \"%6s\"\n", "right");
	return 0;
}
