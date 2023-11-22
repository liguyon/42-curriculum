/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:16:50 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/21 14:16:58 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	*calloc_log(size_t nmemb, size_t size)
{
	void	*ret;

	ret = ft_calloc(nmemb, size);
	if (ret == NULL)
	{
		logger(LOGGER_CRIT, "memory allocation failed");
		return (NULL);
	}
	return (ret);
}
