/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:55:42 by liguyon           #+#    #+#             */
/*   Updated: 2023/08/12 00:45:33 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	utils_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	quicksort_partition(int *array, int start, int end)
{
	int	pivot;
	int	p_index;
	int	i;

	pivot = array[end];
	p_index = start;
	i = start;
	while (i < end)
	{
		if (array[i] <= pivot)
		{
			utils_swap(&array[i], &array[p_index]);
			p_index++;
		}
		i++;
	}
	utils_swap(&array[p_index], &array[end]);
	return (p_index);
}

void	utils_quicksort(int *array, int start, int end)
{
	int	p_index;

	if (start < end)
	{
		p_index = quicksort_partition(array, start, end);
		utils_quicksort(array, start, p_index - 1);
		utils_quicksort(array, p_index + 1, end);
	}
}
