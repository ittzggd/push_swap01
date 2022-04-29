/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:02:41 by hejang            #+#    #+#             */
/*   Updated: 2022/04/29 11:25:01 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack_node	*get_top(t_stack *from, t_stack_node *head, t_stack_node *top
						, t_stack_node *bottom)
{
	t_stack_node	*p_node;

	if (from->current_element_count == 0)
		return (NULL);
	p_node = head->next;
	if (from->current_element_count == 1)
	{
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		top->next->prev = top->prev;
		bottom->next = top->next;
		head->next = top->next;
	}
	p_node->next = p_node;
	p_node->prev = p_node;
	from->current_element_count--;
	return (p_node);
}

int	push(t_stack *to, t_stack_node	*p_node)
{
	t_stack_node	*head;

	if (to == NULL || p_node == NULL)
		return (0);
	head = &to->header_node;
	if (to->current_element_count == 0)
	{
		head->next = p_node;
		head->prev = p_node;
	}
	else
	{
		p_node->next = head->next;
		p_node->prev = head->prev;
		head->next->prev = p_node;
		head->next = p_node;
		head->prev->next = p_node;
	}
	to->current_element_count++;
	return (1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*element;
	t_stack_node	*head;
	t_stack_node	*top;
	t_stack_node	*bottom;

	head = &stack_b->header_node;
	top = head->next;
	bottom = head->prev;
	element = get_top(stack_b, head, top, bottom);
	if (element == NULL)
		return ;
	if (push(stack_a, element))
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*element;
	t_stack_node	*head;
	t_stack_node	*top;
	t_stack_node	*bottom;

	head = &stack_a->header_node;
	top = head->next;
	bottom = head->prev;
	element = get_top(stack_a, head, top, bottom);
	if (element == NULL)
		return ;
	if (push(stack_b, element))
		write(1, "pb\n", 3);
}
