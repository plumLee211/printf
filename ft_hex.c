/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/12/28 19:33:53 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sharp(t_type f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int	ft_recursive_hex(t_type f, size_t n, size_t iter)
{
	int		count;
	int		remainder;
	char	ch;

	count = 0;
	if (n > 0 || (!iter && (f.specifier != 'p' || !f.dot)))
	{
		remainder = n % 16;
		if (f.specifier != 'X')
			ch = HEXLOW[remainder];
		else
			ch = HEXUPP[remainder];
		n /= 16;
		iter = 1;
		count += ft_recursive_hex(f, n, iter);
		count += ft_putchar_fd(ch, 1);
	}
	return (count);
}

int	ft_print_x(t_type f, va_list *ap)
{
	unsigned int	n;
	int				count;
	int				len;

	count = 0;
	n = va_arg(*ap, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !f.prec && f.dot)
		len = 0;
	if (f.prec < 0 || f.prec < len || !f.dot)
		f.prec = len;
	if (f.sharp && n)
		f.width -= 2;
	count += ft_putstr_n_fd(ft_sharp(f), 1, 2 * (f.sharp && f.put_zero && n));
	if (!f.l_allign && f.width > f.prec && (!f.dot || f.neg_prec) && f.put_zero)
		count += ft_putchar_n_fd('0', 1, (f.width - f.prec));
	else if (!f.l_allign && f.width > f.prec)
		count += ft_putchar_n_fd(' ', 1, (f.width - f.prec));
	count += ft_putstr_n_fd(ft_sharp(f), 1, 2 * (f.sharp && !f.put_zero && n));
	count += ft_putchar_n_fd('0', 1, (f.prec - len));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.l_allign && f.width > f.prec)
		count += ft_putchar_n_fd(' ', 1, f.width - f.prec);
	return (count);
}

int	ft_print_p(t_type f, va_list *ap)
{
	long long	n;
	int			count;
	int			len;

	count = 0;
	n = va_arg(*ap, long long);
	len = ft_nbrlen(n, 16);
	len *= !(!n && !f.prec && f.dot);
	if (f.prec < len || !f.dot)
		f.prec = len;
	count += write(1, "0x", 2 * f.put_zero);
	f.width -= 2;
	if (!f.l_allign && f.width > f.prec && !f.dot && f.put_zero)
		count += ft_putchar_n_fd('0', 1, (f.width - f.prec));
	else if (!f.l_allign && f.width > f.prec)
		count += ft_putchar_n_fd(' ', 1, (f.width - f.prec));
	count += write(1, "0x", 2 * !f.put_zero);
	count += ft_putchar_n_fd('0', 1, (f.prec - len) * (n != 0));
	count += ft_putchar_n_fd('0', 1, f.prec * (f.dot && !n));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.l_allign && f.width > f.prec)
		count += ft_putchar_n_fd(' ', 1, f.width - f.prec);
	return (count);
}
