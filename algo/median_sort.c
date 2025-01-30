/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:34:01 by maballet          #+#    #+#             */
/*   Updated: 2025/01/30 16:07:01 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cpy_sort(t_stack *stack)
{
	int	i;
	int	next_sup;
	int	min;
	int	temp;

	min = find_min(stack);
	temp = stack->array[0];
	stack->array[0] = stack->array[min];
	stack->array[min] = temp;
	i = 0;
	while (i < stack->length - 1)
	{
		next_sup = find_closest_sup(stack->array[i], stack);
		if (next_sup != i + 1)
		{
			temp = stack->array[i + 1];
			stack->array[i + 1] = stack->array[next_sup];
			stack->array[next_sup] = temp;
		}
		i++;
	}
}

int		find_median(t_stack *a)
{
	int	i;
	t_stack	copy;
	int	median;

	i = 0;
	copy.length = a->length;
	copy.array = a->array;
	cpy_sort(&copy);
	if (a->length % 2 == 0)
		median = (copy.array[a->length / 2 - 1] + copy.array[a->length / 2]) / 2;
	else
		median = copy.array[a->length / 2];
	free(copy.array);
	return (median);
}

void	median_sort(t_stack *a, t_stack *b)
{
	int	median;

	median = find_median(a);
	ft_printf("median : %d\n", median);
	while (a->length > 3)
		if (a->array[0] >= median)
			push(b, a, "pb\n");
		else
		{
			push(b, a, "pb\n");
			rotate(b, NULL, "rb\n");
		}
}
