/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:22:28 by maballet          #+#    #+#             */
/*   Updated: 2025/02/05 12:52:52 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest(t_stack *dest, t_stack *src)
{
	int	i;
	int	cheapest;
	int	index_of_cheapest;
	int	index_of_closest;
	int	cost;

	i = 0;
	index_of_cheapest = 0;
	cheapest = INT_MAX;
	cost = INT_MAX;
	while (i < src->length)
	{
		index_of_closest = find_closest_sup(src->array[i], dest);
		if (i <= src->length / 2)
			cost = count_cost_01 (dest, &index_of_closest, &i);
		else
			cost = count_cost_02 (dest, src, &index_of_closest, &i);
		if (cost < cheapest)
		{
			cheapest = cost;
			index_of_cheapest = i;
		}
		i++;
	}
	return (index_of_cheapest);
}

int	count_cost_01(t_stack *dest, int *index_of_closest, int *i)
{
	int	cost;

	cost = 0;
	if (*index_of_closest <= dest->length / 2)
	{
		if (*index_of_closest > *i)
			cost = *index_of_closest;
		else if (*index_of_closest < *i)
			cost = *i;
		else
			cost = dest->length - *index_of_closest + *i;
	}
	return (cost);
}

int	count_cost_02(t_stack *dest, t_stack *src, int *index_of_closest, int *i)
{
	int	cost;

	cost = 0;
	if (*index_of_closest <= dest->length / 2)
		cost = *index_of_closest + (src->length - *i);
	else
	{
		if ((dest->length - *index_of_closest) > (src->length - *i))
			cost = dest->length - *index_of_closest;
		else
			cost = src->length - *i;
	}
	return (cost);
}
