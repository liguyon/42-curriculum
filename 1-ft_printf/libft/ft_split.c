/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:04:48 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/26 16:29:11 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_iter(char **res, int index)
{
	while (--index >= 0)
		free(res[index]);
	free(res);
	return (NULL);
}

static char	**make_array_split(char const *s, char c)
{
	int		i;
	int		size;
	char	**res;

	size = 0;
	i = -1;
	while (s[++i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		size++;
		if (!ft_strchr(&s[i], c))
			break ;
		i += (ft_strchr(&s[i], c) - &s[i]) - 1;
	}
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = NULL;
	return (res);
}

static char	**ft_split_alt(char const *s, char c, char **res)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (s[++i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		if (!ft_strchr(&s[i], c))
		{
			res[++j] = ft_strdup(&s[i]);
			if (!res[j])
				return (ft_free_iter(res, j));
			break ;
		}
		res[++j] = ft_substr(s, i, ft_strchr(&s[i], c) - &s[i]);
		if (!res[j])
			return (ft_free_iter(res, j));
		i += ft_strchr(&s[i], c) - &s[i] - 1;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = make_array_split(s, c);
	if (!res)
		return (NULL);
	return (ft_split_alt(s, c, res));
}
