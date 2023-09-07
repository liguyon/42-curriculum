/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:45:28 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/13 00:48:41 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delim(char c, const char *delim)
{
	int	i;

	i = -1;
	while (delim[++i])
	{
		if (c == delim[i])
			return (1);
	}
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*token = NULL;
	char		*start;

	if (str)
		token = str;
	if (!token)
		return (NULL);
	while (*token && is_delim(*token, delim))
		token++;
	if (*token == '\0')
	{
		token = NULL;
		return (NULL);
	}
	start = token;
	while (*token && !is_delim(*token, delim))
		token++;
	if (*token)
	{
		*token = '\0';
		token++;
	}
	return (start);
}
