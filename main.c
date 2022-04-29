/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hejang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:00:14 by hejang            #+#    #+#             */
/*   Updated: 2022/04/30 05:14:21 by hejang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = create_stack();
	if (argc > 1)
	{
		change_arg(argc, argv, stack_a);
		if (check_sort(stack_a) == 1)
			return (0);
		sort_stack(stack_a);
	}
	return (0);
}

void	sort_less_than_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		exit(1);
	if (stack_a->current_element_count == 2)
		sort_two_elements();
	else if (stack_a->current_element_count == 3)
		sort_three_elements(stack_a, stack_b);
	else if (stack_a->current_element_count == 4)
		sort_four_elements(stack_a, stack_b);
	else if (stack_a->current_element_count == 5)
		sort_five_elements(stack_a, stack_b);
	exit(0);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
