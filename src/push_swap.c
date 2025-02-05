/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:23 by maballet          #+#    #+#             */
/*   Updated: 2025/02/05 13:13:33 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stack *stack_a, t_stack *stack_b, char **numbers)
{
	if (char_checker(numbers) == 1)
		return (1);
	if (int_overflowchecker(stack_a, numbers) == 1)
		return (1);
	if (int_doublechecker(stack_a) == 1)
		return (1);
	sort(stack_a, stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		ret;

	if (argc < 2)
		return (0);
	stack_a.length = 0;
	stack_a.array = malloc((argc - 1) * sizeof(int));
	stack_b.length = 0;
	stack_b.array = malloc((argc - 1) * sizeof(int));
	if (stack_a.array == NULL || stack_b.array == NULL)
		ret = EXIT_FAILURE;
	else
		ret = push_swap(&stack_a, &stack_b, argv);
	free(stack_a.array);
	free(stack_b.array);
	return (ret);
}
