/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 07:32:13 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/06 15:24:48 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include "libft.h"

char	*ft_strchr_gnl(const char *s, int c)
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

	if (!ft_strchr_gnl(stream, '\n'))
	{
		free(stream);
		return (NULL);
	}
	end = ft_strchr_gnl(stream, '\n') - stream;
	res = ft_substr(stream, end + 1, ft_strlen(stream) - end -1);
	free(stream);
	return (res);
}

char	*read_to_stream(int fd, char *stream)
{
	int		rd;
	char	*buf;
	char	*tmp;

	buf = malloc(sizeof(char) * (GNL_BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	while (!ft_strchr_gnl(stream, '\n') && rd)
	{
		rd = read(fd, buf, GNL_BUFFER_SIZE);
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
	static char	*stream[GNL_MAX_FD];
	char		*line;

	if (fd < 0 || GNL_BUFFER_SIZE < 1)
		return (NULL);
	stream[fd] = read_to_stream(fd, stream[fd]);
	if (!stream[fd])
		return (NULL);
	if (ft_strchr_gnl(stream[fd], '\n') != NULL)
		line = ft_substr(stream[fd], 0,
				(ft_strchr_gnl(stream[fd], '\n') - stream[fd]) + 1);
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
