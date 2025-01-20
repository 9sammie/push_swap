/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:54:49 by maballet          #+#    #+#             */
/*   Updated: 2025/01/20 16:17:35 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_b(int **stack, int argc)
{
	int a_start;
	int	b_start;

	if (stack_count(stack[0], argc) == 0)
		return ;
	a_start = start_of_stack(stack[0], argc);
	b_start = start_of_stack(stack[1], argc);
	stack [1][b_start - 1] = stack [0][a_start];
	stack [0][a_start] = '\0';
}

void	push_a(int **stack, int argc)
{
	int a_start;
	int	b_start;

	if (stack_count(stack[1], argc) == 0)
		return ;
	a_start = start_of_stack(stack[0], argc);
	b_start = start_of_stack(stack[1], argc);
	stack [0][a_start - 1] = stack[1][b_start];
	stack [1][b_start] = '\0';
}
