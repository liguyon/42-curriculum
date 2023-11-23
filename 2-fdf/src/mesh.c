/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:23:55 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 15:43:17 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	mesh_vertices_alloc(t_mesh *mesh)
{
	int	i;

	mesh->vertices = calloc_log(1, mesh->height * sizeof(*mesh->vertices));
	if (mesh->vertices == NULL)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < mesh->height)
	{
		mesh->vertices[i] = calloc_log(
				1, mesh->width * sizeof(**mesh->vertices));
		if (mesh->vertices[i] == NULL)
		{
			while (--i >= 0)
				free(mesh->vertices[i]);
			free(mesh->vertices);
			mesh->vertices = NULL;
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	mesh_init(t_data *data, const char *filename)
{
	t_mesh	*mesh;
	int		ret;

	mesh = calloc_log(1, sizeof(*mesh));
	if (mesh == NULL)
		return (EXIT_FAILURE);
	data->mesh = mesh;
	mesh->scale = (t_vec3){1.0f, 1.0f, 1.0f};
	ret = parse(mesh, filename);
	if (ret == EXIT_SUCCESS)
	{
		logger(LOGGER_INFO,
			"loaded mesh [file:'%s' ; vertices:%d]",
			filename, mesh->height * mesh->width);
	}
	return (ret);
}

void	mesh_destroy(t_data *data)
{
	int	i;

	if (data->mesh->vertices != NULL)
	{
		i = -1;
		while (++i < data->mesh->height)
			free(data->mesh->vertices[i]);
		free(data->mesh->vertices);
	}
	if (data->mesh)
	{
		free(data->mesh);
		data->mesh = NULL;
		logger(LOGGER_INFO, "destroyed mesh");
	}
}
