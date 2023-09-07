/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:52:53 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/26 16:22:06 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	itohex_len(unsigned int n)
{
	int		itohex_len;

	if (n == 0)
		return (1);
	itohex_len = 0;
	while (n > 0)
	{
		n /= 16;
		itohex_len++;
	}
	return (itohex_len);
}

static void	itohex_l(unsigned int n, int len, char *res)
{
	int		i;
	char	*base;

	base = "0123456789abcdef";
	res[len] = '\0';
	i = -1;
	while (n > 0)
	{
		res[++i] = base[n % 16];
		n /= 16;
	}
	ft_strrev(res);
}

static void	itohex_u(unsigned int n, int len, char *res)
{
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	res[len] = '\0';
	i = -1;
	while (n > 0)
	{
		res[++i] = base[n % 16];
		n /= 16;
	}
	ft_strrev(res);
}

static char	*itohex(unsigned int n, char fmt)
{
	char	*res;
	int		len;

	len = itohex_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (!n)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	if (fmt == 'x')
		itohex_l(n, len, res);
	else if (fmt == 'X')
		itohex_u(n, len, res);
	return (res);
}

int	ft_printf_hex(unsigned int nbr, char fmt)
{
	char	*n;
	int		printed;

	n = itohex((unsigned int)nbr, fmt);
	if (!n)
		return (0);
	printed = ft_printf_str(n);
	free(n);
	return (printed);
}
