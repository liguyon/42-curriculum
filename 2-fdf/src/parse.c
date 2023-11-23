/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:09:04 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 16:48:46 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>

static bool	parse_file(const char *filename, char *buffer)
{
	t_stream	stream;

	stream = (t_stream){.fd = 0, .rd = 1, .ptr = buffer, .ret = EXIT_FAILURE};
	stream.fd = open(filename, O_RDONLY);
	if (stream.fd < 3)
		logger(LOGGER_CRIT, "could not open file '%s'", filename);
	else
	{
		while (stream.rd > 0)
		{
			stream.rd = read(stream.fd, stream.buf, PARSE_READ_SIZE);
			if (stream.rd == -1)
			{
				logger(LOGGER_CRIT, "error occured during call to read()");
				break ;
			}
			ft_memcpy(stream.ptr, stream.buf, stream.rd);
			stream.ptr += stream.rd;
		}
		if (stream.rd == 0)
			stream.ret = EXIT_SUCCESS;
		close(stream.fd);
	}
	return (stream.ret);
}

static void	parse_mesh_dimensions(t_mesh *mesh, char *buffer)
{
	int		i;
	int		state;

	state = word_outside;
	i = -1;
	while (buffer[++i] != '\0')
	{
		if (mesh->height == 0)
		{
			if (ft_isspace(buffer[i]))
				state = word_outside;
			else if (state == word_outside)
			{
				state = word_inside;
				mesh->width++;
			}
		}
		if (buffer[i] == '\n')
			mesh->height++;
	}
}

static int	parse_mesh(t_mesh *mesh, char *buffer)
{
	int		x;
	int		y;
	int		i;
	char	*token;

	parse_mesh_dimensions(mesh, buffer);
	if (mesh->width < 1 || mesh->height < 1)
		return (EXIT_FAILURE);
	if (mesh_vertices_alloc(mesh) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	i = 0;
	token = ft_strtok(buffer, " \n");
	y = -1;
	while (++y < mesh->height)
	{
		x = -1;
		while (++x < mesh->width)
		{
			mesh->vertices[y][x].x = (float)x - mesh->width / 2.0f;
			mesh->vertices[y][x].y = (float)y - mesh->height / 2.0f;
			mesh->vertices[y][x].y *= -1.0f;
			mesh->vertices[y][x].z = -((float)ft_atoi(token));
			token = ft_strtok(NULL, " \n");
		}
	}
	return (EXIT_SUCCESS);
}

int	parse(t_mesh *mesh, const char *filename)
{
	char	*buffer;
	int		ret;

	if (ft_strlen(filename) < 5
		|| ft_strncmp(".fdf", &filename[ft_strlen(filename) - 4], 4) != 0)
	{
		logger(LOGGER_CRIT, "invalid file format");
		return (EXIT_FAILURE);
	}
	buffer = calloc_log(1, (int)1e3 * PARSE_FILE_SIZE);
	if (buffer == NULL)
		return (EXIT_FAILURE);
	if (parse_file(filename, buffer) == EXIT_FAILURE)
	{
		free(buffer);
		return (EXIT_FAILURE);
	}
	ret = parse_mesh(mesh, buffer);
	free(buffer);
	return (ret);
}
