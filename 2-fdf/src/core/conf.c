/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:21:23 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/23 21:07:27 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (EXIT_SUCCESS);
}

void	conf_destroy(t_data *data)
{
	if (data->conf != NULL)
	{
		free(data->conf);
		data->conf = NULL;
	}
}
