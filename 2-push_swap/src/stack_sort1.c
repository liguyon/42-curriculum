/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:01:27 by liguyon           #+#    #+#             */
/*   Updated: 2023/10/09 18:53:53 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	stack_sort_selection_aux(t_stack *a, t_stack *b, int max, int index)
{
	while (stack_peek(b) != max)
	{
		if (index < b->top / 2)
			stack_rrb(b, true);
		else
			stack_rb(b, true);
	}
	stack_pa(a, b, true);
}

void	stack_sort_selection(t_stack *a, t_stack *b, int end)
{
	int	index;
	int	i;
	int	max;

	while (--end >= -1)
	{
		max = stack_peek(b);
		i = -1;
		index = 0;
		while (++i <= b->top)
		{
			if (b->data[i] > max)
			{
				max = b->data[i];
				index = i;
			}
		}
		stack_sort_selection_aux(a, b, max, index);
	}
}

void	stack_sort(t_stack *a, t_stack *b)
{
	if (a->size_max <= 3)
		stack_sort_3(a);
	else if (a->size_max <= 5)
		stack_sort_5(a, b);
	else
		stack_sort_quicksort(a, b);
}
