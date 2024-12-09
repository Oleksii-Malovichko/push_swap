/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:21:55 by omalovic          #+#    #+#             */
/*   Updated: 2024/12/09 22:21:44 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int **stack_a, int *stack_a_len)
{
	if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[0] > (*stack_a)[2])
		rotate_a(*stack_a, *stack_a_len);
	else if ((*stack_a)[1] > (*stack_a)[2] && (*stack_a)[1] > (*stack_a)[0])
		reverse_rotate_a(*stack_a, *stack_a_len);
	if ((*stack_a)[0] > (*stack_a)[1])
		swap_a(stack_a, *stack_a_len);
}

int	find_smallest(int *stack_a, int stack_a_len)
{
	int	smallest;
	int	smallest_index;
	int	i;

	i = 1;
	smallest = stack_a[0];
	smallest_index = 0;
	while (i < stack_a_len)
	{
		if (smallest > stack_a[i])
		{
			smallest = stack_a[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

int	find_biggest(int *stack_a, int stack_a_len)
{
	int	biggest;
	int	biggest_index;
	int	i;

	i = 1;
	biggest = stack_a[0];
	biggest_index = 0;
	while (i < stack_a_len)
	{
		if (biggest < stack_a[i])
		{
			biggest = stack_a[i];
			biggest_index = i;
		}
		i++;
	}
	return (biggest_index);
}

void	sort_selection(int **stack_a, int *stack_a_len, int **stack_b, int *stack_b_len)
{
	int	smallest_index;

	while (*stack_a_len > 3)
	{
		smallest_index = find_smallest(*stack_a, *stack_a_len);
		get_item(stack_a, stack_a_len, smallest_index);
		push_b(stack_b, stack_b_len, stack_a, stack_a_len);
	}
	sort_three(stack_a, stack_a_len);
	while (*stack_b_len > 0)
		push_a(stack_a, stack_a_len, stack_b, stack_b_len);
}

void	sort_selection_reverse(int **stack_a, int *stack_a_len)
{
	int	smallest_index;
	int	*stack_b;
	int	stack_b_len;

	stack_b = NULL;
	stack_b_len = 0;
	while (*stack_a_len > 0)
	{
		smallest_index = find_biggest(*stack_a, *stack_a_len);
		get_item(stack_a, stack_a_len, smallest_index);
		push_b(&stack_b, &stack_b_len, stack_a, stack_a_len);
	}
	while (stack_b_len > 0)
		push_a(stack_a, stack_a_len, &stack_b, &stack_b_len);
	free(stack_b);
}
