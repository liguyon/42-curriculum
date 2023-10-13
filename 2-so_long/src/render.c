/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:52 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/13 13:30:02 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	render(t_data *data)
{
	t_sprite	s;

	s = (t_sprite){.atlas = data->atlases[2], .atlas_x = 0, .atlas_y = 0, .atlas_w = 64*6, .atlas_h = 64*2, .scale = 3};
	sprite_render(data, &s, 0, 0);
}
