/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:52:42 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/26 16:19:33 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str)
{
	int	i;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	return (i);
}

int	ft_printf_int(int nbr)
{
	int		printed;
	char	*n;

	n = ft_itoa(nbr);
	if (!n)
		return (0);
	printed = ft_printf_str(n);
	free(n);
	return (printed);
}

int	ft_printf_fmt(char fmt, va_list pa)
{
	int	printed;

	printed = 0;
	if (fmt == 'c')
	{
		ft_putchar_fd(va_arg(pa, int), 1);
		printed++;
	}
	else if (fmt == 's')
		printed += ft_printf_str(va_arg(pa, char *));
	else if (fmt == 'p')
		printed += ft_printf_ptr(va_arg(pa, void *));
	else if (fmt == 'd' || fmt == 'i')
		printed += ft_printf_int(va_arg(pa, int));
	else if (fmt == 'u')
		printed += ft_printf_uint(va_arg(pa, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		printed += ft_printf_hex(va_arg(pa, unsigned int), fmt);
	else if (fmt == '%')
	{
		ft_putchar_fd('%', 1);
		printed++;
	}
	return (printed);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		pa;
	const char	*p;
	int			printed;

	va_start(pa, fmt);
	p = fmt;
	printed = 0;
	while (*p)
	{
		if (*p != '%')
		{
			ft_putchar_fd(*p, 1);
			printed++;
		}
		else
		{
			p++;
			printed += ft_printf_fmt(*p, pa);
		}
		p++;
	}
	va_end(pa);
	return (printed);
}
