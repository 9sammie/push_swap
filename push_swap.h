/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:58:49 by maballet          #+#    #+#             */
/*   Updated: 2025/01/09 17:19:09 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct	stack
{
	void			*content;
	struct stack	*next;
}
                stack;

stack	**push_swap(char **number);
stack	*new_node(void *number);
void	pile_addback(stack **current_pile, stack *new);
stack	stack_init(char **argv);
int		ps_atoi(char *nptr);
void	ps_lstclear(stack **lst, void (*del)(void *));

#endif