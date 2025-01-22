/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:45:57 by maballet          #+#    #+#             */
/*   Updated: 2025/01/22 16:23:59 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		sort(t_stack *stack_a, t_stack *stack_b, int op_count)
{
	while (sort_check(stack_a) == 1)
	{
	if (stack_a->length == 2)
	{
		swap(stack_a, NULL, "sa");
		op_count++;
	}
	if (stack_a->length == 3)
		op_count += sort_3(stack_a, op_count);
	if (stack_a->length == 5) 
		sort_5(stack_a);
	}	
	return (op_count);
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

int		sort_3(t_stack *stack, int op_count)
{
	
	while ()
}
