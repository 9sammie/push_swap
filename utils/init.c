/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:26:49 by maballet          #+#    #+#             */
/*   Updated: 2025/01/22 14:21:05 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     init(t_stack *stack_a, t_stack *stack_b, char **numbers, int argc)
{
	stack_a->length = 0;
	stack_a->array = ft_calloc(argc - 1, sizeof(int));
	stack_b->length = 0;
	stack_b->array = ft_calloc(argc - 1, sizeof(int));
	if (stack_a->array == NULL || stack_b->array == NULL)
	{
		free_stack(stack_a, stack_b);
		return (1);
	}
	if (char_checker(numbers) == 1)
		return (1);
    if (int_overflowchecker(stack_a, numbers) == 1)
		return (1);
	if (int_doublechecker(stack_a) == 1)
		return (1);
	return (0);
}

int		char_checker(char **argv)
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
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		int_doublechecker(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (stack_a->array[i])
	{
		j = i;
		while (stack_a->array[j])
		{
			if (stack_a->array[i] == stack_a->array[j] && i != j)
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		int_overflowchecker(t_stack *stack_a, char **numbers)
{
	int		i;
	long	check;

	i = 0;
	while (numbers[i + 1] != NULL)
	{
		check = ft_atoi(numbers[i + 1]);
		if (check > INT_MAX || check < INT_MIN)
		{
			ft_printf("Error\n");
			return (1);
		}
		stack_a->array[i] = check;
		stack_a->length++;
		i++;
	}
	return (0);
}
