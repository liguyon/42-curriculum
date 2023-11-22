/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <ligyuon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:53:02 by liguyon           #+#    #+#             */
/*   Updated: 2023/07/10 17:11:46 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"
#include "libft.h"
#include <inttypes.h>

static void	ft_putptr_fd(uintptr_t ptr, int fd)
{
	if (ptr > 15)
		ft_putptr_fd(ptr / 16, fd);
	if (ptr % 16 > 9)
		ft_putchar_fd(ptr % 16 - 10 + 'a', fd);
	else
		ft_putchar_fd(ptr % 16 + '0', fd);
}

int	ft_printf_ptr(void *ptr)
{
	uintptr_t	p;
	int			printed;

	printed = 0;
	p = (uintptr_t)ptr;
	if (ptr)
	{
		printed += write(1, "0x", 2);
		ft_putptr_fd((uintptr_t)ptr, 1);
		while (p)
		{
			p /= 16;
			printed++;
		}
	}
	else
		printed += ft_printf_str("(nil)");
	return (printed);
}
