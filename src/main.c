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

	ft_printf("Hello <%s>world! <%d> <%d>", "PAM PAM", 12345, -6789);
    ft_putchar("\n");
    printf("Hello <%s>world! <%d> <%d>", "PAM PAM", 12345, -6789);
	//printf("%d", 423);
	return 0;
}

