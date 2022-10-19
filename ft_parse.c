/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/10/04 20:33:14 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_type	ft_reset(void)
{
	t_type	new;

	new.l_allign = 0;
	new.put_zero = 0;
	new.width = 0;
	new.prec = 0;
	new.neg_prec = 0;
	new.specifier = 0;
	new.dot = 0;
	new.put_plus = 0;
	new.put_space = 0;
	new.sharp = 0;
	return (new);
}

static	t_type	ft_parse_bonus(char *str, t_type f)
{
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '+')
			f.put_plus = 1;
		if (*str == ' ')
			f.put_space = 1;
		if (*str == '#')
			f.sharp = 1;
		str++;
	}
	return (f);
}

static t_type	ft_parse_width(char *str, t_type f)
{
	int	sp;

	sp = 0;
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '-')
			f.l_allign = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			f.put_zero = 1;
		else if ((*str > '0' && *str <= '9') && !sp)
		{
			f.width = ft_atoi(str);
			sp = 1;
		}
		str++;
	}
	return (f);
}

static t_type	ft_parse_precision(char *str, t_type f)
{
	int	sp;

	sp = 0;
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if (ft_isdigit(*str) && !sp)
		{
			f.prec = ft_atoi(str);
			sp = 1;
		}
		str++;
	}
	return (f);
}

int	ft_parse(char *str, va_list *ap)
{
	t_type	new;

	new = ft_parse_width(str, ft_reset());
	new = ft_parse_bonus(str, new);
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
		str++;
	if (*str == '.' && !new.specifier)
	{
		new.dot = 1;
		new = ft_parse_precision(str + 1, new);
		while (!ft_strchr(SPECIFIERS, *str))
			str++;
	}
	if (new.width < 0)
	{
		new.l_allign = 1;
		new.width *= -1;
	}
	new.specifier = *str;
	new.neg_prec = new.prec < 0;
	return (ft_print_format(new, ap));
}
