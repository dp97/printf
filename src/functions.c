/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpetrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:45:26 by dpetrov           #+#    #+#             */
/*   Updated: 2016/12/31 12:56:38 by dpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				dp_wcslen(const wchar_t *s)
{
	const wchar_t	*p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}

char				*ft_wide_string(wchar_t *s)
{
	int				i;
	unsigned char	*ch;
	char			*res;
	size_t			len;

	len = dp_wcslen(s);
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ch = (unsigned char*)&s[i];
		res[i] = ch[0];
		i++;
	}
	return (res);
}

char				*number_to_char(unsigned long long value, \
		char c, int *width, int *flag)
{
	char			*buf;
	char			alt_form[2];
	int				i;

	i = 0;
	alt_form[0] = 0;
	if ((buf = (char *)malloc(sizeof(char) * 40)) == NULL)
		return (0);
	if (c == 'x' || c == 'X')
	{
		if (convert_x(buf, flag, value, (c == 'X') ? 1 : 0) == 0)
		{
			free(buf);
			buf = NULL;
			return (0);
		}
	}
	else if (c == 'o')
	{
		if (*flag & ALT_FORM)
			if (value == 0)
			{
				*flag |= STRING_FLAG;
				dp_strcpy(buf, "0");
				return (buf);
			}
		convert_o(buf, flag, value);
	}
	else if (c == 'u')
		convert_u(buf, flag, value);
	else if (c == 'b')
		ft_itoa_base(buf, value, 2, 0);
	else if (c == 'i')
		convert_i(buf, flag, value);
	if (*flag & MAX_PRINT && (width[1] == 0) && value == 0)
	{
		free(buf);
		buf = 0;
	}
	return (buf);
}
