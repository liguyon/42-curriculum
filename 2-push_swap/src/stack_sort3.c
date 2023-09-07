/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:27:48 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/06 15:35:00 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_sort_3(t_stack *a)
{
	if (a->top == 1 && stack_peek(a) > a->data[0])
		stack_sa(a, true);
	else if (a->top == 2)
	{
		if (a->data[2] < a->data[1] && a->data[1] > a->data[0]
			&& a->data[2] < a->data[0])
		{
			stack_sa(a, true);
			stack_ra(a, true);
		}
		else if (a->data[2] > a->data[1] && a->data[2] < a->data[0])
			stack_sa(a, true);
		else if (a->data[2] < a->data[1] && a->data[2] > a->data[0])
			stack_rra(a, true);
		else if (a->data[2] > a->data[1] && a->data[2] > a->data[0]
			&& a->data[1] < a->data[0])
			stack_ra(a, true);
		else if (a->data[2] > a->data[1] && a->data[2] > a->data[0]
			&& a->data[1] > a->data[0])
		{
			stack_sa(a, true);
			stack_rra(a, true);
		}
	}
}

static int	stack_min(t_stack *stack)
{
	int	min;
	int	i;

	i = 0;
	min = stack->data[0];
	while (++i <= stack->top)
	{
		if (stack->data[i] < min)
			min = stack->data[i];
	}
	return (min);
}

static int	stack_get_item_index(t_stack *stack, int item)
{
	int	i;

	i = -1;
	while (++i <= stack->top)
	{
		if (stack->data[i] == item)
			return (i);
	}
	return (-1);
}

static void	stack_pb_min(t_stack *a, t_stack *b)
{
	int	min;
	int	index_min;

	min = stack_min(a);
	index_min = stack_get_item_index(a, min);
	if (index_min >= a->top / 2)
	{
		while (stack_peek(a) != min)
			stack_ra(a, true);
		stack_pb(a, b, true);
	}
	else
	{
		while (stack_peek(a) != min)
			stack_rra(a, true);
		stack_pb(a, b, true);
	}
}

void	stack_sort_5(t_stack *a, t_stack *b)
{
	int	size;

	size = a->top + 1;
	if (a->top < 3)
		stack_sort_3(a);
	else
	{
		stack_pb_min(a, b);
		if (a->top == 3)
			stack_pb_min(a, b);
		stack_sort_3(a);
		stack_pa(a, b, true);
		if (size == 5)
			stack_pa(a, b, true);
	}
}
