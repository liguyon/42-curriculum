/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/13 13:35:20 by liguyon          ###   ########.fr       */
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
	data->atlases[4] = atlas_load(data, "assets/sprites/human_spellcast.xpm");
	data->atlases[5] = atlas_load(data, "assets/sprites/dungeon_tiles.xpm");
	data->atlases[6] = atlas_load(data, "assets/sprites/font.xpm");
	i = -1;
	while (++i < 7)
	{
		if (data->atlases[i] == NULL)
			return (false);
	}
	return (true);
}
