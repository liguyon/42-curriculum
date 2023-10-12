/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/12 07:23:11 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

bool	load(t_data *data, const char *map_filename)
{
	if (parse(data->map, map_filename) == false)
		return (false);
	data->atlases[0] = atlas_load(data, "assets/sprites/skeleton_walk.xpm");
	if (data->atlases[0] == NULL)
		return (false);
	return (true);
}
