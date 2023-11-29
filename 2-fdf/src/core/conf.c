/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:21:23 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 02:51:22 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	conf_load_palette_3(t_data *data, int palette)
{
	if (palette == palette_3)
	{
		data->conf->col[0] = 0x000000;
		data->conf->col[1] = 0x8800ff;
		data->conf->col[2] = 0x0000ff;
		data->conf->col[3] = 0x00ffff;
		data->conf->col[4] = 0x00ff00;
		data->conf->col[5] = 0xffff00;
		data->conf->col[6] = 0xff8800;
		data->conf->col[7] = 0xff0000;
		data->conf->col[8] = 0xffffff;
	}
}

static void	conf_load_palette_2(t_data *data, int palette)
{
	if (palette == palette_2)
	{
		data->conf->col[0] = 0x150406;
		data->conf->col[1] = 0x302137;
		data->conf->col[2] = 0x403868;
		data->conf->col[3] = 0x345893;
		data->conf->col[4] = 0x187C9E;
		data->conf->col[5] = 0x009EA8;
		data->conf->col[6] = 0x00C1AD;
		data->conf->col[7] = 0x86DEB7;
		data->conf->col[8] = 0xD9F5E6;
	}
	else
		conf_load_palette_3(data, palette);
}

void	conf_load_palette(t_data *data, int palette)
{
	if (palette == palette_1)
	{
		data->conf->col[0] = 0x000000;
		data->conf->col[1] = 0x19053A;
		data->conf->col[2] = 0x42005A;
		data->conf->col[3] = 0x741058;
		data->conf->col[4] = 0xAC2243;
		data->conf->col[5] = 0xD94225;
		data->conf->col[6] = 0xF5780C;
		data->conf->col[7] = 0xF6BF27;
		data->conf->col[8] = 0xFCFF94;
	}
	else
		conf_load_palette_2(data, palette);
}

int	conf_init(t_data *data)
{
	t_conf	*conf;

	conf = calloc_log(1, sizeof(*conf));
	if (conf == NULL)
		return (EXIT_FAILURE);
	data->conf = conf;
	conf->window_width = 1600;
	conf->window_height = 900;
	conf->window_title = "FdF";
	conf->fps = 60;
	conf->vp_width = 1400;
	conf->prop_width = conf->window_width - conf->vp_width;
	conf->sf = 0.5f;
	conf_load_palette(data, palette_1);
	logger(LOGGER_INFO, "loaded default config");
	return (EXIT_SUCCESS);
}

void	conf_destroy(t_data *data)
{
	if (data->conf != NULL)
	{
		free(data->conf);
		data->conf = NULL;
		logger(LOGGER_INFO, "destroyed config");
	}
}
