/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:14:46 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/06 15:33:16 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>

typedef struct s_part {
	int	pushed;
	int	rotated;
	int	median;
	int	i;	
}	t_part;

typedef struct s_stack {
	int	size_max;
	int	top;
	int	*data;
}	t_stack;

// stack->data is not a dynamic array
// therefore it should be created with enough space to store all args
t_stack	*stack_create(int size);
void	stack_destroy(t_stack *stack);
void	stack_load_args(t_stack *stack, int ac, char *av[]);
int		stack_peek(t_stack *stack);
void	stack_push(t_stack *stack, int item);
int		stack_pop(t_stack *stack);
bool	stack_is_empty(t_stack *stack);
bool	stack_is_sorted(t_stack *stack);
void	stack_debug(t_stack *a, t_stack *b);
void	stack_sa(t_stack *a, bool verbose);
void	stack_sb(t_stack *b, bool verbose);
void	stack_ss(t_stack *a, t_stack *b, bool verbose);
void	stack_pa(t_stack *a, t_stack *b, bool verbose);
void	stack_pb(t_stack *a, t_stack *b, bool verbose);
void	stack_ra(t_stack *a, bool verbose);
void	stack_rb(t_stack *b, bool verbose);
void	stack_rr(t_stack *a, t_stack *b, bool verbose);
void	stack_rra(t_stack *a, bool verbose);
void	stack_rrb(t_stack *b, bool verbose);
void	stack_rrr(t_stack *a, t_stack *b, bool verbose);
void	stack_sort(t_stack *a, t_stack *b);
void	stack_sort_3(t_stack *a);
void	stack_sort_5(t_stack *a, t_stack *b);
void	stack_sort_selection(t_stack *a, t_stack *b, int end);
void	stack_sort_quicksort(t_stack *a, t_stack *b);

#endif