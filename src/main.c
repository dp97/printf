/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:11:04 by anonymous         #+#    #+#             */
/*   Updated: 2016/12/02 09:42:56 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main()
{
    void    *p;

	ft_printf("Hello <%s>world! <%X> <%p>", "PAM PAM", 999, p, 4294967295);
    ft_printf( "%u", 17u);
    ft_putchar('\n');
    printf("Hello <%s>world! <%X> <%p> |%D|", "PAM PAM", 999, p, 42949);
    printf( "%u", 17u );
	return 0;
}

