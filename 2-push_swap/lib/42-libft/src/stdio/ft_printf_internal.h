/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:06:56 by liguyon           #+#    #+#             */
/*   Updated: 2023/07/28 08:35:55 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H

# include <stdarg.h>

int	ft_printf_fmt(char fmt, va_list pa);
int	ft_printf_int(int nbr);
int	ft_printf_str(char *str);
int	ft_printf_str(char *str);
int	ft_printf_uint(unsigned int nbr);
int	ft_printf_ptr(void *ptr);
int	ft_printf_hex(unsigned int nbr, char fmt);

#endif