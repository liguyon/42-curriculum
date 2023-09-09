/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:59:30 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/24 21:02:26 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	tmp;

	if (str)
	{
		len = ft_strlen(str);
		i = -1;
		j = len - 1;
		while (++i < len / 2)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			j--;
		}
	}
	return (str);
}
