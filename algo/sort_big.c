/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:35:42 by maballet          #+#    #+#             */
/*   Updated: 2025/01/24 18:01:55 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	push(stack_b, stack_a, "pb\n");
	push(stack_b, stack_a, "pb\n");
	if (stack_b->array[0] < stack_b->array[1])
	{
		if (stack_a->array[0] > stack_a->array[1])
			swap(stack_a, stack_b, "ss\n");
		else	
			swap(stack_b, NULL, "sb\n");
	}
	j = stack_a->length;
	while(j > 3)
	{
		i = find_cheapest(stack_a, stack_b);
		push_cheapest(stack_a, stack_b, i);
		j--;
	}
	sort_3(stack_a);
	reverse_rotate(stack_a, NULL, "rra\n");
}
