/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:35:37 by liguyon           #+#    #+#             */
/*   Updated: 2023/11/21 16:21:20 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		ret;

	if (argc != 2)
	{
		ft_printf("\nusage: ./fdf path/to/file.ber\n\n");
		return (EXIT_SUCCESS);
	}
	ret = EXIT_FAILURE;
	data = calloc_log(1, sizeof(*data));
	if (data == NULL)
		return (EXIT_FAILURE);
	if (mesh_init(data, argv[1]) == EXIT_SUCCESS)
		ret = run(data);
	terminate(data);
	free(data);
	return (ret);
}