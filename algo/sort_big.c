/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:35:42 by maballet          #+#    #+#             */
/*   Updated: 2025/01/29 20:55:33 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_rotate(int nbr, t_stack *stack)
{
	if (stack->array[stack->length - 1] < stack->array[0] && stack->array[stack->length - 1] > nbr)
	{
		reverse_rotate(stack, NULL, "rra\n");
		return (1);
	}
	return (0);
}

void	max_on_top(t_stack *stack)
{
	int	i;
	int	max;
	int	rev_op;

	i = 0;
	max = find_max(stack);
	rev_op = stack->length - max;
	if (max <= stack->length / 2)
		while (max-- > 0)
			rotate(stack, NULL, "rb\n");
	if (max > stack->length / 2)
		while (rev_op-- > 0)
			reverse_rotate(stack, NULL, "rrb\n");
}
void	min_on_top(t_stack *stack)
{
	int	i;
	int	min;
	int	rev_op;

	i = 0;
	min = find_min(stack);
	rev_op = stack->length - min;
	if (min <= stack->length / 2)
		while (min-- > 0)
			rotate(stack, NULL, "ra\n");
	if (min > stack->length / 2)
		while (rev_op-- > 0)
			reverse_rotate(stack, NULL, "rra\n");
}

int		find_median(t_stack *a)
{
	int	i;
	int	next_big;
	int	cur_big;

	i = 0;
	cur_big = find_max(a);
	while (i < a->length / 2)
	{
		next_big = find_closest_inf(a->array[cur_big], a);
		cur_big = next_big;
		i++;
	}
	return (cur_big);
}

void	median_sort(t_stack *a, t_stack *b)
{
	int	median;

	median = find_median(a);
	ft_printf("%d\n", median);
	while (a->length > 3)
	{
		if (a->array[0] >= median)
			push(b, a, "pb\n");
		else
		{
			push(b, a, "pb\n");
			rotate(b, NULL, "rb\n");
		}
	}
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	
	j = 3;
	median_sort(stack_a, stack_b);
	sort_3(stack_a);
	while(stack_b->length > 0)
	{
		i = find_cheapest(stack_a, stack_b);
		if(j > 0)
		{
			if (check_rotate(stack_b->array[0], stack_a) != 0)
				j--;
			if (check_rotate(stack_b->array[0], stack_a) != 0)
				j--;
		}
	 	push_cheapest(stack_a, stack_b, i);
	}
	min_on_top(stack_a);
}
