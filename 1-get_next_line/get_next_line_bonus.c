/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:32:13 by liguyon           #+#    #+#             */
/*   Updated: 2023/04/23 22:51:09 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		res = malloc(sizeof(char) * (1 + ft_strlen(s) - start));
	else
		res = malloc(sizeof(char) * (1 + len));
	if (!res)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			res[i] = s[start + i];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*rm_line(char *stream)
{
	char	*res;
	int		end;

	if (!ft_strchr(stream, '\n'))
	{
		free(stream);
		return (NULL);
	}
	end = ft_strchr(stream, '\n') - stream;
	res = ft_substr(stream, end + 1, ft_strlen(stream) - end -1);
	free(stream);
	return (res);
}

char	*read_to_stream(int fd, char *stream)
{
	int		rd;
	char	*buf;
	char	*tmp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	while (!ft_strchr(stream, '\n') && rd)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		tmp = ft_strjoin(stream, buf);
		free(stream);
		stream = tmp;
	}
	free(buf);
	return (stream);
}

char	*get_next_line(int fd)
{
	static char	*stream[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	stream[fd] = read_to_stream(fd, stream[fd]);
	if (!stream[fd])
		return (NULL);
	if (ft_strchr(stream[fd], '\n') != NULL)
		line = ft_substr(stream[fd], 0,
				(ft_strchr(stream[fd], '\n') - stream[fd]) + 1);
	else
	{
		if (!(*stream[fd]))
			line = NULL;
		else
			line = ft_strdup(stream[fd]);
	}
	stream[fd] = rm_line(stream[fd]);
	return (line);
}
