/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/12 07:55:09 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	render(t_data *data)
{
	t_sprite	s;

	s = (t_sprite){.atlas = data->atlases[0], .atlas_x = 0, .atlas_y = 0, .atlas_w = 64, .atlas_h = 64, .scale = 1};
	sprite_render(data, &s, 0, 0);
}
