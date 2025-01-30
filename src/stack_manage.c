/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:53:41 by maballet          #+#    #+#             */
/*   Updated: 2025/01/30 17:53:43 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *dest, int val) //ajoute au dernier element
{
	dest->array[dest->length] = val;
	dest->length++;
}

int		stack_pop(t_stack *stack) //enleve le dernier element. pourquoi ne pas decrementer apres ?
{
	stack->length--;
	return (stack->array[stack->length]);
}

int		stack_shift(t_stack *stack) //enleve le 1er element
{
	int	tmp;

	tmp = stack->array[0];
	ft_memmove(stack->array, stack->array + 1, (stack->length) * sizeof(int));
	stack->length--;
	return (tmp);
}

void	stack_unshift(t_stack *stack, int val) //ajoute au premier element
{
	ft_memmove(stack->array + 1, stack->array, (stack->length) * sizeof(int));
	stack->array[0] = val;
	stack->length++;
}
