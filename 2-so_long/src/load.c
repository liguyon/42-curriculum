/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/20 13:34:33 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

bool	load(t_data *data, const char *map_filename)
{
	int	i;

	if (parse(data->map, map_filename) == false)
		return (false);
	data->atlases[0] = atlas_load(data, "assets/sprites/skeleton_walk.xpm");
	data->atlases[1] = atlas_load(data, "assets/sprites/skeleton_slash.xpm");
	data->atlases[2] = atlas_load(data, "assets/sprites/human_walk.xpm");
	data->atlases[3] = atlas_load(data, "assets/sprites/human_hurt.xpm");
	data->atlases[ATLAS_TILES] = atlas_load(data, "assets/sprites/tiles.xpm");
	data->atlases[5] = atlas_load(data, "assets/sprites/font.xpm");
	i = -1;
	while (++i < ATLAS_COUNT)
	{
		if (data->atlases[i] == NULL)
			return (false);
	}
	return (true);
}
