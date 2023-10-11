/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:50:15 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/11 06:47:13 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

bool	load(t_data *data, const char *map_filename)
{
	if (parse(data->map, map_filename) == false)
		return (false);
	return (true);
}
