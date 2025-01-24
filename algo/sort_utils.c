/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:24:22 by maballet          #+#    #+#             */
/*   Updated: 2025/01/24 18:37:39 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//find and return the biggest number of the given stack.
int		find_max(t_stack *stack)
{
	int	max;
	int	i;

	max = stack->array[0];
	i = 0;
	while (i < stack->length)
	{
		if (max < stack->array[i])
			max = i;
		i++;
	}
	return (i);
}

//find and return the smallest number of the given stack.
int		find_min(t_stack *stack)
{
	int	min;
	int	i;

	min = stack->array[0];
	i = 0;
	while (i < stack->length)
	{
		if (min > stack->array[i])
			min = i;
		i++;
	}
	return (i);
}

int		find_closest_inf(int nbr, t_stack *stack)
{
	int	closest;
	int	distance;
	int	i;

	closest = stack->length;
	distance = 0;
	i = 0;
	while (i < stack->length)
	{
		if (nbr > stack->array[i])
			distance = nbr - stack->array[i];
		if (distance < closest)
			closest = i;
		i++;
	}
	if (closest == stack->length)
		i = find_max(stack);
	return (i);
}

int		find_cheapest(t_stack *stack_a, t_stack *stack_b)
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
	while (i < stack_a->length - 3) //stop when only 3 in stack a
	{
		index_of_closest = find_closest_inf(stack_a->array[i], stack_b);
		ft_printf("%d\n", index_of_closest);
		if (i <= stack_a->length / 2)
		{
			if (index_of_closest <= stack_b->length / 2)
				if (index_of_closest > i)
					cost = index_of_closest;
				else
					cost = i;
			else
				cost = stack_b->length - index_of_closest + i;
		}
		else
		{
			if (index_of_closest <= stack_b->length / 2)
				cost = index_of_closest + (stack_a->length - i);
			else
				if ((stack_b->length - index_of_closest) > (stack_a->length - i))
					cost = stack_b->length - index_of_closest;
				else
					cost = stack_a->length - i;
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

void	push_cheapest(t_stack *stack_a, t_stack *stack_b, int cheapest)
{
	int	i;
	int closest;

	i = 0;
	closest = find_closest_inf(stack_a->array[cheapest], stack_b);
	if (cheapest <= stack_a->length / 2 && closest <= stack_b->length / 2)
	{
		ft_printf("ok\n");
		while (cheapest != 0 || closest != 0)
		{
			rotate(stack_a, stack_b, "rr\n");
			cheapest--;
			closest--;
		}
		while (cheapest != 0)
		{
			rotate(stack_a, NULL, "ra\n");
			cheapest--;
		}
		while (closest != 0)
		{
			rotate(stack_b, NULL, "rb\n");
			closest--;
		}
		push(stack_b, stack_a, "pb\n");
	}
	else if (cheapest > stack_a->length / 2 && closest > stack_b->length / 2)
	{
		ft_printf("ok\n");
		cheapest = stack_a->length - cheapest;
		closest = stack_b->length - closest;
		while (cheapest != 0 || closest != 0)
		{
			reverse_rotate(stack_a, stack_b, "rrr\n");
			cheapest--;
			closest--;
		}
		while (cheapest != 0)
		{
			reverse_rotate(stack_a, NULL, "rra\n");
			cheapest--;
		}
		while (closest != 0)
		{
			reverse_rotate(stack_b, NULL, "rrb\n");
			closest--;
		}
		push(stack_b, stack_a, "pb\n");
	}
	else if (cheapest <= stack_a->length / 2 && closest > stack_b->length / 2)
	{
		closest = stack_b->length / 2;
		while (cheapest != 0)
		{
			rotate(stack_a, NULL, "ra\n");
			cheapest--;
		}
		while (closest != 0)
		{
			reverse_rotate(stack_b, NULL, "rrb\n");
			closest--;
		}
		push(stack_b, stack_a, "pb\n");
	}
	else
	{
		closest = stack_b->length / 2;
		while (cheapest != 0)
		{
			reverse_rotate(stack_a, NULL, "rra\n");
			cheapest--;
		}
		while (closest != 0)
		{
			rotate(stack_b, NULL, "rb\n");
			closest--;
		}
		push(stack_b, stack_a, "pb\n");
	}
}
