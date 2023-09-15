/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liguyon <liguyon@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 20:55:57 by liguyon           #+#    #+#             */
/*   Updated: 2023/09/15 06:04:49 by liguyon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"
#include "utils.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

/*
 * test whether the argument is a valid integer:
 * -> contains only digits, '+', or '-'
 * -> the sign can only be at the beginning
 * -> is between INT_MIN and INT_MAX
*/
static bool	check_int(char *str)
{
	int		i;
	int		j;
	long	nbr;

	if (!(ft_isdigit(str[0]) || str[0] == '+' || str[0] == '-'))
		return (false);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	j = 0;
	while (str[j + i])
	{
		if (!ft_isdigit(str[j + i]))
			return (false);
		j++;
	}
	if (j > 11)
		return (false);
	nbr = ft_atol(str);
	if (!(nbr >= INT_MIN && nbr <= INT_MAX))
		return (false);
	return (true);
}

/*
 * test whether there are no duplicates
*/
static bool	check_duplicates(int ac, char *av[])
{
	int		*sorted_args;
	int		i;

	sorted_args = malloc(sizeof(int) * ac);
	if (!sorted_args)
	{
		if (write(2, "Error\n", 6) != -1)
			exit(0);
		else
			exit(1);
	}
	i = -1;
	while (++i < ac)
		sorted_args[i] = ft_atoi(av[i]);
	utils_quicksort(sorted_args, 0, ac - 1);
	while (--i > 0)
	{
		if (sorted_args[i] == sorted_args[i - 1])
		{
			free(sorted_args);
			return (false);
		}
	}
	free(sorted_args);
	return (true);
}

/*
 * check each integer
 * if there is only one valid integer, stack is sorted
 * check duplicates
 * return true if args are valid
*/
bool	check_args(int ac, char *av[])
{
	int	i;

	i = -1;
	while (++i < ac)
	{
		if (check_int(av[i]) == false)
			return (false);
	}
	if (ac == 1)
		exit(0);
	if (check_duplicates(ac, av) == false)
		return (false);
	return (true);
}
