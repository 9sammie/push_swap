/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:51:52 by maballet          #+#    #+#             */
/*   Updated: 2025/03/10 13:33:38 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_instruction(char *cmd, t_stack *a, t_stack *b)
{
	if (ft_strncmp(cmd, "sa\n", 4) == 0)
		swap(a, NULL, NULL);
	else if (ft_strncmp(cmd, "sb\n", 4) == 0)
		swap(b, NULL, NULL);
	else if (ft_strncmp(cmd, "ss\n", 4) == 0)
		swap(a, b, NULL);
	else if (ft_strncmp(cmd, "pa\n", 4) == 0)
		push(a, b, NULL);
	else if (ft_strncmp(cmd, "pb\n", 4) == 0)
		push(b, a, NULL);
	else if (ft_strncmp(cmd, "ra\n", 4) == 0)
		rotate(a, NULL, NULL);
	else if (ft_strncmp(cmd, "rb\n", 4) == 0)
		rotate(b, NULL, NULL);
	else if (ft_strncmp(cmd, "rr\n", 4) == 0)
		rotate(a, b, NULL);
	else if (ft_strncmp(cmd, "rra\n", 5) == 0)
		reverse_rotate(a, NULL, NULL);
	else if (ft_strncmp(cmd, "rrb\n", 5) == 0)
		reverse_rotate(b, NULL, NULL);
	else if (ft_strncmp(cmd, "rrr\n", 5) == 0)
		reverse_rotate(a, b, NULL);
	else
		return (1);
	return (0);
}

int	exec_instruct(t_stack *a, t_stack *b)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(0);
	while (line != NULL)
	{
		i = execute_instruction(line, a, b);
		free(line);
		if (i == 1)
		{
			write (2, "Error\n", 6);
			return (1);
		}
		line = get_next_line(0);
	}
	return (0);
}

int	init(t_stack *stack_a, t_stack *stack_b, char **numbers, int argc)
{
	int	i;

	i = 0;
	stack_a->length = 0;
	stack_a->array = malloc((argc - 1) * sizeof(int));
	stack_b->length = 0;
	stack_b->array = malloc((argc - 1) * sizeof(int));
	if (char_checker(numbers) == 1)
		return (1);
	if (int_overflowchecker(stack_a, numbers) == 1)
		return (1);
	if (int_doublechecker(stack_a) == 1)
		return (1);
	i = exec_instruct(stack_a, stack_b);
	if (i == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		ret;

	ret = 0;
	if (argc < 2)
		return (0);
	if (stack_a.array == NULL || stack_b.array == NULL)
		ret = EXIT_FAILURE;
	ret = init(&stack_a, &stack_b, argv, argc);
	if (ret == 1)
	{
		free(stack_a.array);
		free(stack_b.array);
		return (ret);
	}
	if (sort_check(&stack_a) == 0 && stack_b.length == 0)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
	}
	free(stack_a.array);
	free(stack_b.array);
	return (ret);
}
