/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/11/08 22:50:42 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_type
{
	int		l_allign;
	int		put_zero;
	int		width;
	int		prec;
	int		neg_prec;
	char	specifier;
	int		dot;
	int		put_plus;
	int		put_space;
	int		sharp;
}		t_type

# define INT_MIN -2147483648
# define UNIT_MAX 4294967295

# define HEXUPP "0123456789ABCDEF"
# define HEXLOW "0123456789abcdef"
# define SPECIFIERS "cspdiuxX%"
;
int		ft_printf(const char *str, ...);
int		ft_print_format(t_type f, va_list *ap);
int		ft_print_c_per(t_type f, va_list *ap);
int		ft_print_s(t_type f, va_list *ap);
int		ft_print_d_i_u(t_type f, va_list *ap);
int		ft_print_x(t_type f, va_list *ap);
int		ft_print_p(t_type f, va_list *ap);
int		ft_parse(char *str, va_list *ap);

#endif
