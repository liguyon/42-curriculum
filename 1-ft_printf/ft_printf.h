/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:36:58 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/26 15:36:26 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf_str(char *str);
int	ft_printf_nbr(int nbr);
int	ft_printf_uint(unsigned int nbr);
int	ft_printf_ptr(void *ptr);
int	ft_printf_hex(unsigned int nbr, char fmt);
int	ft_printf_fmt(char fmt, va_list pa);
int	ft_printf(const char *fmt, ...);

#endif
