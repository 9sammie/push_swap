/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:26:49 by maballet          #+#    #+#             */
/*   Updated: 2025/02/06 18:21:30 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	char_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!(argv))
		return (1);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_putendl_fd("Error", 2);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	int_doublechecker(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->length)
	{
		j = i;
		while (j < stack_a->length)
		{
			if (stack_a->array[i] == stack_a->array[j] && i != j)
			{
				ft_putendl_fd("Error", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	int_overflowchecker(t_stack *stack_a, char **numbers)
{
	int		i;
	long	check;

	i = 0;
	while (numbers[i + 1] != NULL)
	{
		check = ft_atoi(numbers[i + 1]);
		if (check > INT_MAX || check < INT_MIN)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		stack_a->array[i] = check;
		stack_a->length++;
		i++;
	}
	return (0);
}
