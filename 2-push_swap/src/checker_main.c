/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 06:14:14 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/06 15:38:35 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "check_args.h"
#include "libft.h"
#include "stack.h"
#include <unistd.h>

static int	checker_do_op(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp("pa\n", line) == 0)
		stack_pa(a, b, false);
	else if (ft_strcmp("pb\n", line) == 0)
		stack_pb(a, b, false);
	else if (ft_strcmp("sa\n", line) == 0)
		stack_sa(a, false);
	else if (ft_strcmp("sb\n", line) == 0)
		stack_sb(b, false);
	else if (ft_strcmp("ss\n", line) == 0)
		stack_ss(a, b, false);
	else if (ft_strcmp("ra\n", line) == 0)
		stack_ra(a, false);
	else if (ft_strcmp("rb\n", line) == 0)
		stack_rb(b, false);
	else if (ft_strcmp("rr\n", line) == 0)
		stack_rr(a, b, false);
	else if (ft_strcmp("rra\n", line) == 0)
		stack_rra(a, false);
	else if (ft_strcmp("rrb\n", line) == 0)
		stack_rrb(b, false);
	else if (ft_strcmp("rrr\n", line) == 0)
		stack_rrr(a, b, false);
	else
		write(2, "Error\n", 6);
	return (0);
}

int	checker(t_stack *a, t_stack *b)
{
	char	*line;
	int		ret;

	line = get_next_line(0);
	while (line)
	{
		ret = checker_do_op(a, b, line);
		free(line);
		if (ret != 0)
			return (EXIT_FAILURE);
		line = get_next_line(0);
	}
	return (EXIT_SUCCESS);
}

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
			if (checker(a, b) == EXIT_SUCCESS)
			{
				if (!stack_is_sorted(a))
					ft_printf("KO\n");
				else
					ft_printf("OK\n");
			}
			stack_destroy(a);
			stack_destroy(b);
			return (0);
		}
	}
	return (write(2, "Error\n", 6) - 6);
}
