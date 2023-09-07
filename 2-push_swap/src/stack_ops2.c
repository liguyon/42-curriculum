/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:55:02 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/06 15:31:52 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include "libft.h"

void	stack_ra(t_stack *a, bool verbose)
{
	int	i;

	if (a->top > -1)
	{
		i = a->top;
		while (i > 0)
		{
			utils_swap(&a->data[i], &a->data[i - 1]);
			i--;
		}
		if (verbose)
			ft_printf("ra\n");
	}
}

void	stack_rb(t_stack *b, bool verbose)
{
	int	i;

	if (b->top > -1)
	{
		i = b->top;
		while (i > 0)
		{
			utils_swap(&b->data[i], &b->data[i - 1]);
			i--;
		}
		if (verbose)
			ft_printf("rb\n");
	}
}

void	stack_rr(t_stack *a, t_stack *b, bool verbose)
{
	int	i;

	i = a->top;
	while (i > 0)
	{
		utils_swap(&a->data[i], &a->data[i - 1]);
		i--;
	}
	i = b->top;
	while (i > 0)
	{
		utils_swap(&b->data[i], &b->data[i - 1]);
		i--;
	}
	if (verbose && (a->top > -1 || b->top > -1))
		ft_printf("rr\n");
}
