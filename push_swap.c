/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:23 by maballet          #+#    #+#             */
/*   Updated: 2025/01/22 16:15:21 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap(t_stack *stack_a, t_stack *stack_b, char **numbers, int argc)
{
	static int	op_count = 0;
	if (init(stack_a, stack_b, numbers, argc) == 1)
		return (1);
	sort(stack_a, stack_b, op_count);
	return (0);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	ft_printf("\na\n-\n\n");
	while(i < stack_a->length)
	{
		ft_printf("%d\n", stack_a->array[i]);
		i++;
	}
	i = 0;
	ft_printf("\nb\n-\n\n");
	while(i < stack_b->length)
	{
		ft_printf("%d\n", stack_b->array[i]);
		i++;
	}
}

int    main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2 || char_checker(argv) == 1)
		return (0);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (stack_a == NULL || stack_b == NULL)
	{
		free_stack(stack_a, stack_b);
		return (1);
	}
	if (push_swap(stack_a, stack_b, argv, argc) == 1)
	{
		free_stack(stack_a, stack_b);
		return (1);
	}
	print_stack(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return(0);
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->array)
		free(stack_a->array);
	if (stack_b->array)
		free(stack_b->array);
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
}
