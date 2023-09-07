/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:10:17 by liguyon           #+#    #+#             */
/*   Updated: 2023/05/13 21:10:22 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*res;

	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	res = malloc(size);
	if (!res)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr)
	{
		ft_memcpy(res, ptr, size);
		free(ptr);
	}
	return (res);
}
