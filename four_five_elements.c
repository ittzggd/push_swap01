/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:58:34 by hejang            #+#    #+#             */
/*   Updated: 2022/04/30 01:07:13 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*top;

	if (!stack_a || !stack_b)
		ft_error();
	while (stack_a->current_element_count > 3)
	{
		top = stack_a->header_node.next;
		if (top->index == 0 || top->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (!check_sort(stack_a))
		sort_three_elements(stack_a, stack_b);
	if (stack_b->header_node.next->index == 1)
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else
	{
		rb(stack_b);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	sort_four_elements(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_node	*top;

	if (!stack_a || !stack_b)
		ft_error();
	while (stack_a->current_element_count > 3)
	{
		top = stack_a->header_node.next;
		if (top->index == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (!check_sort(stack_a))
		sort_three_elements(stack_a, stack_b);
	pa(stack_a, stack_b);
}
