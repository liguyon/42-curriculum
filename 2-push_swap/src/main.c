/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:51:01 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/06 06:30:08 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"
#include "libft.h"
#include "stack.h"
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (check_args(--argc, ++argv) == true)
	{
		a = stack_create(argc);
		b = stack_create(argc);
		if (a != NULL && b != NULL)
		{
			stack_load_args(a, argc, argv);
			if (!stack_is_sorted(a))
				stack_sort(a, b);
			stack_destroy(a);
			stack_destroy(b);
			return (0);
		}
	}
	if (write(2, "Error\n", 6) != -1)
		return (0);
	else
		return (1);
}
