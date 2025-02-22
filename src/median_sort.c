/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:34:01 by maballet          #+#    #+#             */
/*   Updated: 2025/02/06 18:03:07 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_median(t_stack *a)
{
	int		i;
	t_stack	copy;
	int		median;
	int		med_nbr;

	i = 0;
	copy.length = a->length;
	copy.array = malloc(sizeof(int) * a->length);
	if (copy.array == NULL)
		return (-1);
	while (i < a->length)
	{
		copy.array[i] = a->array[i];
		i++;
	}
	cpy_sort(&copy);
	med_nbr = copy.array[a->length / 2];
	if (a->length % 2 == 0)
		median = med_nbr - 1;
	else
		median = med_nbr;
	free(copy.array);
	return (median);
}

void	median_sort(t_stack *a, t_stack *b)
{
	int	median;

	median = find_median(a);
	push(b, a, "pb");
	while (a->length > 3)
	{
		if (a->array[0] >= median)
			push(b, a, "pb");
		else
		{
			push(b, a, "pb");
			rotate(b, NULL, "rb");
		}
	}
}
