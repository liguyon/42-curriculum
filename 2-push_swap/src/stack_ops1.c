/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:54:38 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/06 15:30:32 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "utils.h"

void	stack_sa(t_stack *a, bool verbose)
{
	if (a->top >= 1)
	{
		utils_swap(&a->data[a->top], &a->data[a->top - 1]);
		if (verbose)
			ft_printf("sa\n");
	}
}

void	stack_sb(t_stack *b, bool verbose)
{
	if (b->top >= 1)
	{
		utils_swap(&b->data[b->top], &b->data[b->top - 1]);
		if (verbose)
			ft_printf("sb\n");
	}
}

void	stack_ss(t_stack *a, t_stack *b, bool verbose)
{
	if (a->top >= 1)
		utils_swap(&a->data[a->top], &a->data[a->top - 1]);
	if (b->top >= 1)
		utils_swap(&b->data[b->top], &b->data[b->top - 1]);
	if (verbose)
		ft_printf("ss\n");
}

void	stack_pa(t_stack *a, t_stack *b, bool verbose)
{
	if (!stack_is_empty(b))
		stack_push(a, stack_pop(b));
	if (verbose)
		ft_printf("pa\n");
}

void	stack_pb(t_stack *a, t_stack *b, bool verbose)
{
	if (!stack_is_empty(a))
		stack_push(b, stack_pop(a));
	if (verbose)
		ft_printf("pb\n");
}
