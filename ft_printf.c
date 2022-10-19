/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/11/08 22:49:43 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(t_type f, va_list *ap)
{
	int	len;

	len = 0;
	if (f.specifier == 'c' || f.specifier == '%')
		len = ft_print_c_per(f, ap);
	if (f.specifier == 's')
		len = ft_print_s(f, ap);
	if (f.specifier == 'd' || f.specifier == 'i' || f.specifier == 'u')
		len = ft_print_d_i_u(f, ap);
	if (f.specifier == 'x' || f.specifier == 'X')
		len = ft_print_x(f, ap);
	if (f.specifier == 'p')
		len = ft_print_p(f, ap);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str != '\0')
				len += ft_parse((char *)str, &ap);
			while (*str != '\0' && !ft_strchr(SPECIFIERS, *str))
				str++;
		}
		else
			len += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(ap);
	return (len);
}
