/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:53:41 by maballet          #+#    #+#             */
/*   Updated: 2025/03/03 15:21:44 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *dest, int val)
{
	dest->array[dest->length] = val;
	dest->length++;
}

int	stack_pop(t_stack *stack)
{
	stack->length--;
	return (stack->array[stack->length]);
}

int	stack_shift(t_stack *stack)
{
	int	tmp;

	tmp = stack->array[0];
	if (stack->length > 1)
		ft_memmove(stack->array, stack->array + 1,
			(stack->length - 1) * sizeof(int));
	stack->length--;
	return (tmp);
}

void	stack_unshift(t_stack *stack, int val)
{
	ft_memmove(stack->array + 1, stack->array, (stack->length) * sizeof(int));
	stack->array[0] = val;
	stack->length++;
}
