/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:31:46 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/30 16:01:47 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static void	*ft_calloc(size_t nmemb, size_t size)
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

void	*calloc_log(size_t nmemb, size_t size)
{
	void	*ret;

	ret = ft_calloc(nmemb, size);
	if (ret == NULL)
	{
		printf(ANSI_BRED "[CRIT] " ANSI_RESET "insufficient memory\n");
		return (NULL);
	}
	return (ret);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (sign * res);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (sign * res);
}
