/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:24:22 by maballet          #+#    #+#             */
/*   Updated: 2025/02/05 15:48:41 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int	max;
	int	i;
	int	index_max;

	index_max = 0;
	max = stack->array[0];
	i = 0;
	while (i < stack->length)
	{
		if (max < stack->array[i])
		{
			max = stack->array[i];
			index_max = i;
		}
		i++;
	}
	return (index_max);
}

int	find_min(t_stack *stack)
{
	int	min;
	int	i;
	int	index_min;

	index_min = 0;
	min = stack->array[0];
	i = 0;
	while (i < stack->length)
	{
		if (min > stack->array[i])
		{
			min = stack->array[i];
			index_min = i;
		}
		i++;
	}
	return (index_min);
}

int	find_closest_inf(int nbr, t_stack *stack)
{
	int	closest;
	int	distance;
	int	index_of_closest;
	int	i;

	index_of_closest = -1;
	closest = INT_MAX;
	i = 0;
	while (i < stack->length)
	{
		if (stack->array[i] < nbr)
		{
			distance = nbr - stack->array[i];
			if (distance < closest)
			{
				closest = distance;
				index_of_closest = i;
			}
		}
		i++;
	}
	if (index_of_closest == -1)
		index_of_closest = find_max(stack);
	return (index_of_closest);
}

int	find_closest_sup(int nbr, t_stack *stack)
{
	int	closest;
	int	distance;
	int	index_of_closest;
	int	i;

	index_of_closest = -1;
	closest = INT_MAX;
	i = 0;
	while (i < stack->length)
	{
		if (stack->array[i] > nbr)
		{
			distance = stack->array[i] - nbr;
			if (distance < closest)
			{
				closest = distance;
				index_of_closest = i;
			}
		}
		i++;
	}
	if (index_of_closest == -1)
		index_of_closest = find_min(stack);
	return (index_of_closest);
}
