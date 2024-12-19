/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:36:08 by alex              #+#    #+#             */
/*   Updated: 2024/12/19 04:39:55 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rr(int *stack_a, int stack_a_len, int *stack_b, int stack_b_len)
{
	rotate_a(stack_a, stack_a_len);
	rotate_b(stack_b, stack_b_len);
}

void	reverse_rotate_a(int *stack_a, int stack_a_len)
{
	int	last_elem;
	int	i;

	if (stack_a_len <= 1)
		return ;
	last_elem = stack_a[stack_a_len - 1];
	i = stack_a_len - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = last_elem;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(int *stack_b, int stack_b_len)
{
	int	last_elem;
	int	i;

	if (stack_b_len <= 1)
		return ;
	last_elem = stack_b[stack_b_len - 1];
	i = stack_b_len - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = last_elem;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_rr(int *stack_a, int stack_a_len,
			int *stack_b, int stack_b_len)
{
	reverse_rotate_a(stack_a, stack_a_len);
	reverse_rotate_b(stack_b, stack_b_len);
}

void	get_item1(int **stack_a, int *stack_a_len, int smallest_index)
{
	if (smallest_index < (*stack_a_len / 2))
	{
		while (smallest_index > 0)
		{
			rotate_a(*stack_a, *stack_a_len);
			smallest_index--;
		}
	}
	else
	{
		smallest_index = *stack_a_len - smallest_index;
		while (smallest_index > 0)
		{
			reverse_rotate_a(*stack_a, *stack_a_len);
			smallest_index--;
		}
	}
}

void	get_item2(int **stack_b, int *stack_b_len, int smallest_index)
{
	if (smallest_index < (*stack_b_len / 2))
	{
		while (smallest_index > 0)
		{
			rotate_b(*stack_b, *stack_b_len);
			smallest_index--;
		}
	}
	else
	{
		smallest_index = *stack_b_len - smallest_index;
		while (smallest_index > 0)
		{
			reverse_rotate_b(*stack_b, *stack_b_len);
			smallest_index--;
		}
	}
}

void	print_a(int *stack_a, int stack_a_len)
{
	printf("Stack_a:\n");
	for (int i = 0; i < stack_a_len; i++)
		printf("%d ", (stack_a)[i]);
	printf("\n");
}
void	print_b(int *stack_a, int stack_a_len)
{
	printf("Stack_b:\n");
	for (int i = 0; i < stack_a_len; i++)
		printf("%d ", (stack_a)[i]);
	printf("\n");
}