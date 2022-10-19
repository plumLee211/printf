/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/11/08 22:49:11 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	sign(t_type f)
{
	if (f.put_plus == 1)
		return ('+');
	return ('-');
}

static int	ft_print_nbr(t_type f, char *nbr, int len, int neg)
{
	int	i;

	i = 0;
	f.width -= (f.put_space && !neg && !f.put_plus && f.width);
	if (neg || f.put_plus)
		i += ft_putchar_n_fd(sign(f), 1, f.put_zero && (!f.dot || f.neg_prec));
	else if (f.put_space)
		i += ft_putchar_n_fd(' ', 1, f.put_zero && !f.dot);
	if (!f.l_allign && f.width > f.prec && (!f.dot || f.neg_prec) && f.put_zero)
		i += ft_putchar_n_fd('0', 1, f.width - f.prec - neg - f.put_plus);
	else if (!f.l_allign && f.width > f.prec)
		i += ft_putchar_n_fd(' ', 1, f.width - f.prec - neg - f.put_plus);
	if (neg || f.put_plus)
		i += ft_putchar_n_fd(sign(f), 1, !f.put_zero || (f.dot && !f.neg_prec));
	else if (f.put_space)
		i += ft_putchar_n_fd(' ', 1, !f.put_zero || f.dot);
	i += ft_putchar_n_fd('0', 1, f.prec - len);
	i += write(1, nbr, len);
	if (f.l_allign && f.width > f.prec)
		i += ft_putchar_n_fd(' ', 1, f.width - f.prec - neg - f.put_plus);
	return (i);
}

int	ft_print_d_i_u(t_type f, va_list *ap)
{
	char	*nbr;
	int		n;
	int		c;
	int		len;
	int		neg;

	c = 0;
	n = va_arg(*ap, int);
	neg = (n < 0 && n != INT_MIN && f.specifier != 'u');
	if (neg)
		f.put_plus = 0;
	if (n < 0 && f.specifier != 'u')
		n *= -1;
	if (n < 0 && f.specifier == 'u')
		nbr = ft_uitoa((unsigned)n);
	else
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f.prec && f.dot)
		len = 0;
	if (f.prec < len || !f.dot)
		f.prec = len;
	c += ft_print_nbr(f, nbr, len, neg);
	free(nbr);
	return (c);
}
