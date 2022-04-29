/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:24:40 by hejang            #+#    #+#             */
/*   Updated: 2022/04/29 10:58:02 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	swap(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*top;
	t_stack_node	*swap;

	if (stack == NULL)
		return (-1);
	head = &stack->header_node;
	top = head->next;
	swap = top->next;
	if (stack->current_element_count < 2)
		return (0);
	swap->prev = top->prev;
	head->next = swap;
	top->next = swap->next;
	swap->next = top;
	top->prev = swap;
	if (stack->current_element_count == 2)
		head->prev = swap->next;
	return (1);
}

void	sa(t_stack	*stack)
{
	if (stack == NULL)
		return ;
	if (swap(stack) == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack	*stack)
{
	if (stack == NULL)
		return ;
	if (swap(stack) == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (swap(stack_a) == 1 || swap(stack_b) == 1)
		write(1, "ss\n", 3);
}
