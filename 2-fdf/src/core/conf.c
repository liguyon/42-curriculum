/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:21:23 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/28 20:38:28 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

static void	conf_load_palette_3(t_data *data, int palette)
{
	if (palette == palette_3)
	{
		data->conf->c_h0 = 0x7d8782;
		data->conf->c_h1 = 0x87968c;
		data->conf->c_h2 = 0xa5b4aa;
		data->conf->c_h3 = 0xd7d7c8;
		data->conf->c_h4 = 0xa5aa8c;
		data->conf->c_h5 = 0xe1d2a5;
		data->conf->c_h6 = 0xcda087;
		data->conf->c_h7 = 0xa05555;
		data->conf->c_h8 = 0x914137;
	}
}

static void	conf_load_palette_2(t_data *data, int palette)
{
	if (palette == palette_2)
	{
		data->conf->c_h0 = 0x150406;
		data->conf->c_h1 = 0x302137;
		data->conf->c_h2 = 0x403868;
		data->conf->c_h3 = 0x345893;
		data->conf->c_h4 = 0x187C9E;
		data->conf->c_h5 = 0x009EA8;
		data->conf->c_h6 = 0x00C1AD;
		data->conf->c_h7 = 0x86DEB7;
		data->conf->c_h8 = 0xD9F5E6;
	}
	else
		conf_load_palette_3(data, palette);
}

void	conf_load_palette(t_data *data, int palette)
{
	if (palette == palette_1)
	{
		data->conf->c_h0 = 0x000000;
		data->conf->c_h1 = 0x19053A;
		data->conf->c_h2 = 0x42005A;
		data->conf->c_h3 = 0x741058;
		data->conf->c_h4 = 0xAC2243;
		data->conf->c_h5 = 0xD94225;
		data->conf->c_h6 = 0xF5780C;
		data->conf->c_h7 = 0xF6BF27;
		data->conf->c_h8 = 0xFCFF94;
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
	conf->scale_factor = 0.75f;
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
