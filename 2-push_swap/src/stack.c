/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:14:41 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/25 12:10:00 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include <unistd.h>

t_stack	*stack_create(int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stack->size_max = size;
	stack->top = -1;
	stack->data = ft_calloc(size, sizeof(*stack->data));
	if (!stack->data)
	{
		free(stack);
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stack);
}

void	stack_destroy(t_stack *stack)
{
	if (stack->data)
		free(stack->data);
	free(stack);
}

void	stack_load_args(t_stack *stack, int ac, char *av[])
{
	while (--ac >= 0)
		stack_push(stack, ft_atoi(av[ac]));
}

// #include <stdio.h>
// void	stack_debug(t_stack *a, t_stack *b)
// {
// 	printf("==========================================================\n");
// 	printf("[a] size_max:%d ; top:%d  || [b] size_max:%d ; top:%d\n", 
// 		a->size_max, a->top, b->size_max, b->top);
// 	printf("--top--                 ||\n");
// 	for (int i = a->top > b->top ? a->top : b->top ; i >= 0 ; i--)
// 	{
// 		if (a->top >= i)
// 			printf("% 11d", a->data[i]);
// 		else
// 			printf("           ");
// 		printf("             ||  ");
// 		if (b->top >= i)
// 			printf("% 11d", b->data[i]);
// 		printf("\n");
// 	}
// 	printf("--bottom--              ||");
// 	printf("\n==========================================================\n\n");
// }