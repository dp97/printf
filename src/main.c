/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:09:09 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/14 16:46:33 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main()
{
    char *np = 0;
    char buf[80] = "12345";
    int     nb = 12345;
    
    
	ft_printf("|%d\n", ft_printf("<%zu> <%s>", sizeof(buf), np));

	printf("|%d\n", printf("<%zu> <%s>", sizeof(buf), np));
    
    ft_printf("\n<%#o><%#x><%#X>\n", nb, nb, nb);
    printf("<%#o><%#x><%#X>\n", nb, nb, nb);
    
    
    ft_printf("just==: \"%-3s\"\n", "left");
    printf("justif: \"%-3s\"\n", "left");
    ft_printf("just==: \"%6s\"\n", "right");
    printf("justif: \"%6s\"\n", "right");
    
    ft_printf("<%d>\n", -223244352);
    printf("<%d>\n", -223244352);
	return 0;
}
