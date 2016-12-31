/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:44:42 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/30 19:48:51 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_flags_1_1(va_list args, int *flag, int width[2])
{
	if (*flag & MAX_PRINT)
	{
		if ((width[1] = va_arg(args, int)) < 0)
			width[1] = 0;
	}
	else
	{
		if ((width[0] = va_arg(args, int)) < 0)
		{
			width[0] = -width[0];
			*flag |= PAD_RIGHT;
		}
	}
	*flag |= STAR_FLAG;
}

static void			ft_flags_1_2(const char *format, int *flag, int width[2])
{
	unsigned short	i;

	i = 0;
	if (*flag & MAX_PRINT)
		i = 1;
	if ((*format == '0') && (width[0] == 0) && (width[1] == 0) \
			&& (!(*flag & MAX_PRINT)) && (!(*flag & PAD_RIGHT)))
		*flag |= ZERO_FLAG;
	if (*flag & STAR_FLAG)
	{
		*flag ^= STAR_FLAG;
		*flag ^= PAD_RIGHT;
		width[0] = 0;
	}
	width[i] *= 10;
	width[i] += (*format) - '0';
}

int					ft_flags_1(const char *format, int *flag, int width[2], \
		va_list args)
{
	if (*format == '#')
		*flag |= ALT_FORM;
	else if (*format == '*')
		ft_flags_1_1(args, flag, width);
	else if (*format == ' ')
		*flag |= SPACE_FLAG;
	else if (*format == '-')
		*flag |= PAD_RIGHT;
	else if (*format == '\'')
		*flag |= COMMA_FLAG;
	else if (*format == '+')
		*flag |= PLUS_SIGN;
	else if (*format == '.')
		*flag |= MAX_PRINT;
	else if (*format >= '0' && *format <= '9')
		ft_flags_1_2(format, flag, width);
	else
		return (0);
	return (1);
}

int					ft_modifiers(const char *format, int *flags)
{
	if (*format == 'h')
	{
		if (*flags & H_FLAG)
			*flags |= HH_FLAG;
		*flags |= H_FLAG;
	}
	else if (*format == 'l')
	{
		if (*flags & L_FLAG)
			*flags |= LL_FLAG;
		*flags |= L_FLAG;
	}
	else if (*format == 'L')
		*flags |= L_FLOAT_FLAG;
	else if (*format == 'j')
		*flags |= INTMAX_T;
	else if (*format == 'z')
		*flags |= SIZE_T;
	else
		return (0);
	return (1);
}
