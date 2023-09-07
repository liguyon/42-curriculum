/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:07:19 by liguyon           #+#    #+#             */
/*   Updated: 2023/05/13 21:09:56 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_error(char const *message)
{
	const char	*color_start;
	const char	*color_reset;
	int			fd;

	fd = STDERR_FILENO;
	color_start = ANSI_COLOR_RED;
	color_reset = ANSI_COLOR_RESET;
	write(fd, color_start, ft_strlen(color_start));
	write(fd, message, ft_strlen(message));
	write(fd, color_start, ft_strlen(color_reset));
}
