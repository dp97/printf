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

	ft_printf("->%d", ft_printf("<%C>%", L'A'));
    ft_putchar('\n');
    printf("->%d", printf("<%c>%", L'A'));
	return 0;
}

