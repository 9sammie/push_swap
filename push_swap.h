/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:58:49 by maballet          #+#    #+#             */
/*   Updated: 2025/01/20 16:03:03 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/inc/libft.h"

int		**push_swap(char **numbers, int argc);
int		int_doublechecker(int *stack_a);
int		char_checker(char **argv);
int		**init(char **numbers, int argc);
int		**int_atolchecker(char **numbers, int argc);
void	free_stacks(int **stack);
int		stack_count(int *stack, int argc);
int 	start_of_stack(int *stack, int argc);
void	swap_a(int **stack);
void    push_b(int **stack, int argc);
void    push_a(int **stack, int argc);

#endif