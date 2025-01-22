/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:58:49 by maballet          #+#    #+#             */
/*   Updated: 2025/01/22 16:08:08 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/libft.h"

typedef struct	s_stack
{
	int	length;
	int	*array;
}				t_stack;

int		push_swap(t_stack *stack_a, t_stack *stack_b, char **numbers, int argc);
int		int_doublechecker(t_stack *stack_a);
int		char_checker(char **argv);
int     init(t_stack *stack_a, t_stack *stack_b, char **numbers, int argc);
int		int_overflowchecker(t_stack *stack_a, char **numbers);
void	stack_push(t_stack *dest, int val);
int		stack_pop(t_stack *stack);
int		stack_shift(t_stack *stack);
void	stack_unshift(t_stack *stack, int val);
void	swap(t_stack *s1, t_stack *s2, char *instruct);
void	push(t_stack *dest, t_stack *src, char *instruct);
void	rotate(t_stack *s1, t_stack *s2, char *instruct);
void	reverse_rotate(t_stack *s1, t_stack *s2, char *instruct);
void	free_stack(t_stack *stack_a, t_stack *stack_b);
int		sort(t_stack *stack_a, t_stack *stack_b, int op_count);
int		sort_check(t_stack *stack);

#endif