/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:28:01 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/22 16:40:48 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>

static int	stack_get_median(t_stack *s, int end)
{
	int	*arr;
	int	med;

	arr = malloc(sizeof(*s->data) * (end + 1));
	if (!arr)
		exit(EXIT_FAILURE);
	ft_memcpy(arr, &s->data[s->top - end], sizeof(*s->data) * (end + 1));
	utils_quicksort(arr, 0, end);
	med = arr[end / 2];
	free(arr);
	return (med);
}

static int	stack_partition_a(t_stack *a, t_stack *b, int end)
{
	t_part	part;

	part = (t_part){.pushed = 0, .i = end, .median = stack_get_median(a, end)};
	while (part.i >= 0)
	{
		if (stack_peek(a) <= part.median)
		{
			stack_pb(a, b, true);
			part.pushed++;
			if (part.pushed > (end + 1) / 2)
				break ;
		}
		else
		{
			if (b->top < a->size_max / 2 && b->top > 1
				&& b->data[b->top] < stack_get_median(b, b->top))
				stack_rr(a, b, true);
			else
				stack_ra(a, true);
		}
		part.i--;
	}
	return (part.pushed);
}

static void	stack_partition_b_aux(t_stack *a, t_stack *b, t_part *part, int end)
{
	while (--part->i >= -1)
	{
		if (stack_peek(b) > part->median)
		{
			stack_pa(a, b, true);
			part->pushed++;
			if (part->pushed > (end + 1) / 2)
				break ;
		}
		else
		{
			stack_rb(b, true);
			part->rotated++;
		}
	}
}

static int	stack_partition_b(t_stack *a, t_stack *b, t_stack *helper, int end)
{
	t_part	part;

	part = (t_part){.pushed = 0, .rotated = 0,
		.i = end, .median = stack_get_median(b, end)};
	stack_partition_b_aux(a, b, &part, end);
	if (helper->top > 0)
	{
		while (--part.rotated >= 0)
			stack_rrb(b, true);
	}
	part.i = -1;
	while (++part.i < part.pushed)
		stack_pb(a, b, true);
	return (part.pushed);
}

void	stack_sort_quicksort(t_stack *a, t_stack *b)
{
	t_stack	*helper;
	int		end;
	int		iter;

	helper = stack_create(a->size_max);
	if (!helper)
		return ;
	while (a->top > 2)
		stack_push(helper, stack_partition_a(a, b, a->top));
	stack_sort_3(a);
	while (!stack_is_empty(helper))
	{
		end = stack_pop(helper) - 1;
		if (end < 18)
			stack_sort_selection(a, b, end);
		else
		{
			iter = stack_partition_b(a, b, helper, end);
			stack_push(helper, end - iter + 1);
			stack_push(helper, iter);
		}
	}
	stack_destroy(helper);
}
