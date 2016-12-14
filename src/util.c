/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:12:48 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/14 16:53:33 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_str_case(char *s, int up_or_low)
{
	int        i;

	i = 0;
	while (s[i])
	{
		if (up_or_low)
		{
			if (s[i] >= 'a' && s[i] <= 'A')
				s[i] += 32;
		}
		else
		{
			if (s[i] >= 'a' && s[i] <= 'A')
				s[i] -= 32;
		}
		i++;
	}
	return (s);
}

void	ft_putc(char c)
{
	write(1, &c, 1);
}

int		ft_len(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_puts(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
