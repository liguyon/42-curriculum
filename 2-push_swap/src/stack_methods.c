/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:52:26 by liguyon           #+#    #+#             */
/*   Updated: 2023/08/12 00:11:02 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_stack *stack, int item)
{
	stack->data[++stack->top] = item;
}

int	stack_pop(t_stack *stack)
{
	return (stack->data[stack->top--]);
}

int	stack_peek(t_stack *stack)
{
	return (stack->data[stack->top]);
}

bool	stack_is_sorted(t_stack *stack)
{
	int	i;

	if (stack->top >= 0)
	{
		i = -1;
		while (++i < stack->top)
		{
			if (stack->data[i] < stack->data[i + 1])
				return (false);
		}
	}
	return (true);
}

bool	stack_is_empty(t_stack *stack)
{
	return (stack->top == -1);
}
