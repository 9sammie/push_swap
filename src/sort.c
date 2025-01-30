/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:45:57 by maballet          #+#    #+#             */
/*   Updated: 2025/01/30 17:53:16 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (sort_check(stack_a) != 0)
	{
		if (stack_a->length == 2)
			swap(stack_a, NULL, "sa");
		else if (stack_a->length == 3)
			sort_3(stack_a);
		else
			sort_big(stack_a, stack_b);
	}
}

int		sort_check(t_stack *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->length)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	sort_3(t_stack *stack)
{
	if (find_max(stack) == 0)
	{
		rotate(stack, NULL, "ra\n");
		if (sort_check(stack) != 0)
			swap(stack, NULL, "sa\n");
	}
	else if (find_min(stack) == 0)
	{
		swap(stack, NULL, "sa\n");
		rotate(stack, NULL, "ra\n");
	}
	else
	{
		if (find_min(stack) == 1)
			swap(stack, NULL, "sa\n");
		else
			reverse_rotate(stack, NULL, "rra\n");
	}
}
