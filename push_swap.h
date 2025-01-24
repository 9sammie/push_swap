/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:58:49 by maballet          #+#    #+#             */
/*   Updated: 2025/01/24 17:46:59 by maballet         ###   ########lyon.fr   */
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
int		int_overflowchecker(t_stack *stack_a, char **numbers);
void	stack_push(t_stack *dest, int val);
int		stack_pop(t_stack *stack);
int		stack_shift(t_stack *stack);
void	stack_unshift(t_stack *stack, int val);
void	swap(t_stack *s1, t_stack *s2, char *instruct);
void	push(t_stack *dest, t_stack *src, char *instruct);
void	rotate(t_stack *s1, t_stack *s2, char *instruct);
void	reverse_rotate(t_stack *s1, t_stack *s2, char *instruct);
void	sort(t_stack *stack_a, t_stack *stack_b);
int		sort_check(t_stack *stack);
void	sort_3(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
int		find_cheapest(t_stack *stack_a, t_stack *stack_b);
int		find_closest_inf(int nbr, t_stack *stack);
void	sort_big(t_stack *stack_a, t_stack *stack_b);
void	push_cheapest(t_stack *stack_a, t_stack *stack_b, int cheapest);

#endif