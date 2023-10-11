/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:26:16 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/11 08:09:44 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	*malloc_log(size_t size, char *file, int line)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		logger(LOGGER_CRIT, "failed to allocate memory");
		logger_track(file, line);
		return (NULL);
	}
	else
		return (ptr);
}

void	*calloc_log(size_t nmemb, size_t size, char *file, int line)
{
	void	*ptr;

	ptr = ft_calloc(nmemb, size);
	if (!ptr)
	{
		logger(LOGGER_CRIT, "failed to allocate memory");
		logger_track(file, line);
		return (NULL);
	}
	else
		return (ptr);
}

bool	in_charset(char c, const char *charset)
{
	int	i;

	i = -1;
	while (charset[++i] != '\0')
	{
		if (c == charset[i])
			return (true);
	}
	return (false);
}