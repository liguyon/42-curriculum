/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:44:00 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/29 13:57:53 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <X11/X.h>

static int	inputs_process_structure(t_data *data)
{
	mlx_loop_end(data->grph->mlx_ptr);
	return (EXIT_SUCCESS);
}

static void	inputs_bind(t_data *data)
{
	mlx_hook(data->grph->win_ptr, DestroyNotify, StructureNotifyMask,
		inputs_process_structure, data);
	mlx_hook(data->grph->win_ptr, KeyPress, KeyPressMask,
		inputs_process_keypress, data);
	mlx_hook(data->grph->win_ptr, ButtonPress, ButtonPressMask,
		inputs_process_mpress, data);
	mlx_hook(data->grph->win_ptr, ButtonRelease, ButtonReleaseMask,
		inputs_process_mrelease, data);
}

int	inputs_init(t_data *data)
{
	t_inputs	*input;

	input = calloc_log(1, sizeof(*input));
	if (input == NULL)
		return (EXIT_FAILURE);
	data->inputs = input;
	inputs_bind(data);
	logger(LOGGER_INFO, "initialized inputs");
	return (EXIT_SUCCESS);
}

void	inputs_destroy(t_data *data)
{
	if (data->inputs != NULL)
	{
		free(data->inputs);
		data->inputs = NULL;
		logger(LOGGER_INFO, "destroyed inputs");
	}
}
