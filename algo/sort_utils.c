/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:24:22 by maballet          #+#    #+#             */
/*   Updated: 2025/01/28 19:52:04 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//find and return the biggest number of the given stack.
int		find_max(t_stack *stack)
{
	int	max;
	int	i;
	int index_max;

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

//find and return the smallest number of the given stack.
int		find_min(t_stack *stack)
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
int		find_closest_inf(int nbr, t_stack *stack)
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

int		find_closest_sup(int nbr, t_stack *stack)
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

int		find_cheapest(t_stack *dest, t_stack *src)
{
	int	i;
	int	cheapest;
	int	index_of_cheapest;
	int index_of_closest;
	int cost;

	i = 0;
	index_of_cheapest = 0;
	cheapest = INT_MAX;
	cost = INT_MAX;
	while (i < src->length) //stop when only 3 in stack a
	{
		index_of_closest = find_closest_sup(src->array[i], dest);
		if (i <= src->length / 2) //if in the upper part of stack a
		{
			if (index_of_closest <= dest->length / 2)
				if (index_of_closest > i)
					cost = index_of_closest;
				else
					cost = i;
			else
				cost = dest->length - index_of_closest + i;
		}
		else //if in lower part
		{
			if (index_of_closest <= dest->length / 2)
				cost = index_of_closest + (src->length - i);
			else
				if ((dest->length - index_of_closest) > (src->length - i))
					cost = dest->length - index_of_closest;
				else
					cost = src->length - i;
		}
		if (cost < cheapest)
		{
			cheapest = cost;
			index_of_cheapest = i;
		}
		i++;
	}
	return (index_of_cheapest);
}

void	push_cheapest(t_stack *a, t_stack *b, int cheapest)
{
	int	i;
	int closest;

	i = 0;
	closest = find_closest_sup(b->array[cheapest], a);
	if (cheapest <= b->length / 2 && closest <= a->length / 2)
	{
		while (cheapest > 0 && closest > 0)
		{
			rotate(b, a, "rr\n");
			cheapest--;
			closest--;
		}
		while (cheapest > 0)
		{
			rotate(b, NULL, "rb\n");
			cheapest--;
		}
		while (closest > 0)
		{
			rotate(a, NULL, "ra\n");
			closest--;
		}
		push(a, b, "pa\n");
	}
	else if (cheapest > b->length / 2 && closest > a->length / 2)
	{
		cheapest = b->length - cheapest;
		closest = a->length - closest;
		while (cheapest > 0 && closest > 0)
		{
			reverse_rotate(b, a, "rrr\n");
			cheapest--;
			closest--;
		}
		while (cheapest > 0)
		{
			reverse_rotate(b, NULL, "rrb\n");
			cheapest--;
		}
		while (closest > 0)
		{
			reverse_rotate(a, NULL, "rra\n");
			closest--;
		}
		push(a, b, "pa\n");
	}
	else if (cheapest <= b->length / 2 && closest > a->length / 2)
	{
		closest = a->length - closest;
		while (cheapest > 0)
		{
			rotate(b, NULL, "rb\n");
			cheapest--;
		}
		while (closest > 0)
		{
			reverse_rotate(a, NULL, "rra\n");
			closest--;
		}
		push(a, b, "pa\n");
	}
	else
	{
		cheapest = b->length - cheapest;
		while (cheapest > 0)
		{
			reverse_rotate(b, NULL, "rrb\n");
			cheapest--;
		}
		while (closest > 0)
		{
			rotate(a, NULL, "ra\n");
			closest--;
		}
		push(a, b, "pa\n");
	}
}
