/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:49:12 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/06 15:32:38 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "utils.h"

void	stack_rra(t_stack *a, bool verbose)
{
	int	i;

	if (a->top > -1)
	{
		i = -1;
		while (++i < a->top)
			utils_swap(&a->data[i], &a->data[i + 1]);
		if (verbose)
			ft_printf("rra\n");
	}
}

void	stack_rrb(t_stack *b, bool verbose)
{
	int	i;

	if (b->top > -1)
	{
		i = -1;
		while (++i < b->top)
			utils_swap(&b->data[i], &b->data[i + 1]);
		if (verbose)
			ft_printf("rrb\n");
	}
}

void	stack_rrr(t_stack *a, t_stack *b, bool verbose)
{
	int	i;

	if (a->top > -1)
	{
		i = -1;
		while (++i < a->top)
			utils_swap(&a->data[i], &a->data[i + 1]);
	}
	if (b->top > -1)
	{
		i = -1;
		while (++i < b->top)
			utils_swap(&b->data[i], &b->data[i + 1]);
	}
	if (verbose && (a->top > -1 || b->top > -1))
		ft_printf("rrr\n");
}
