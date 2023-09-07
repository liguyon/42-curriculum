/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:42:25 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/17 16:09:13 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	if (((nmemb > 65535 || size > 65535)) && (size_t)-1 / nmemb < size)
		return (NULL);
	res = malloc(sizeof(char) * size * nmemb);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
	{
		((char *)res)[i] = '\0';
		i++;
	}
	return (res);
}
