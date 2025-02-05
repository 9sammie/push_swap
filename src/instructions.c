/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:02:19 by maballet          #+#    #+#             */
/*   Updated: 2025/02/05 15:29:23 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s1, t_stack *s2, char *instruct)
{
	int	tmp;

	tmp = s1->array[0];
	s1->array[0] = s1->array[1];
	s1->array[1] = tmp;
	if (s2 != NULL)
	{
		tmp = s2->array[0];
		s2->array[0] = s2->array[1];
		s2->array[1] = tmp;
		if (instruct != NULL)
			ft_putendl_fd(instruct, 1);
		return ;
	}
	if (instruct != NULL)
		ft_putendl_fd(instruct, 1);
}

void	push(t_stack *dest, t_stack *src, char *instruct)
{
	if (src->array[0] == '\0')
		return ;
	stack_unshift(dest, stack_shift(src));
	if (instruct != NULL)
		ft_putendl_fd(instruct, 1);
}

void	rotate(t_stack *s1, t_stack *s2, char *instruct)
{
	stack_push(s1, stack_shift(s1));
	if (s2 != NULL)
	{
		stack_push(s2, stack_shift(s2));
		if (instruct != NULL)
			ft_putendl_fd(instruct, 1);
		return ;
	}
	if (instruct != NULL)
		ft_putendl_fd(instruct, 1);
}

void	reverse_rotate(t_stack *s1, t_stack *s2, char *instruct)
{
	stack_unshift(s1, stack_pop(s1));
	if (s2 != NULL)
	{
		stack_unshift(s2, stack_pop(s2));
		if (instruct != NULL)
			ft_putendl_fd(instruct, 1);
		return ;
	}
	if (instruct != NULL)
		ft_putendl_fd(instruct, 1);
}
