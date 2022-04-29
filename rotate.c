/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:52:24 by hejang            #+#    #+#             */
/*   Updated: 2022/04/29 10:57:01 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	rotate(t_stack *stack)
{
	t_stack_node	*head;
	t_stack_node	*top;

	if (stack == NULL)
		return (-1);
	if (stack->current_element_count < 2)
		return (0);
	head = &stack->header_node;
	top = head->next;
	head->prev = top;
	head->next = top->next;
	return (1);
}

void	ra(t_stack	*stack_a)
{	
	if (stack_a == NULL)
		return ;
	if (rotate(stack_a) == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	if (stack_b == NULL)
		return ;
	if (rotate(stack_b) == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (rotate(stack_a) == 1 || rotate(stack_b) == 1)
		write(1, "rr\n", 3);
}
