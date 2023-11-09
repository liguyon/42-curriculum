/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:05:58 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/18 09:15:21 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	c = (unsigned char)c;
	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	if ((unsigned char)c == '\0')
		return (&str[i]);
	while (i--)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
	}
	return (NULL);
}
