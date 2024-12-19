/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:13:12 by alex              #+#    #+#             */
/*   Updated: 2024/12/19 04:43:30 by alex             ###   ########.fr       */
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

void	sort_selection_reverse(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len)
{
	int	biggest_index;
	int	pushed_b;

	pushed_b = 0;
	while (*stack_a_len > 0)
	{
		biggest_index = find_biggest(*stack_a, *stack_a_len);
		get_item2(stack_a, stack_a_len, biggest_index);
		push_a(stack_b, stack_b_len, stack_a, stack_a_len);
		pushed_b++;
	}
	while (*stack_b_len > 0)
	{
		if (pushed_b == 0)
			break ;
		push_b(stack_a, stack_a_len, stack_b, stack_b_len);
		pushed_b--;
	}
}

void	sort_selection(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len)
{
	int	smallest_index;
	int	pushed_b;

	pushed_b = 0;
	smallest_index = find_smallest(*stack_a, *stack_a_len);
	while (*stack_a_len > 3)
	{
		smallest_index = find_smallest(*stack_a, *stack_a_len);
		get_item1(stack_a, stack_a_len, smallest_index);
		push_b(stack_b, stack_b_len, stack_a, stack_a_len);
		pushed_b++;
	}
	sort_three(stack_a, stack_a_len);
	while (*stack_b_len > 0)
	{
		if (pushed_b == 0)
			break ;
		push_a(stack_a, stack_a_len, stack_b, stack_b_len);
		pushed_b--;
	}
}

int	find_pivot(const int *stack_a, int stack_a_len)
{
	int	*copy;
	int	i;
	int	j;
	int	pivot;

	i = 0;
	copy = ft_strcpy(stack_a, stack_a_len);
	while (i < stack_a_len - 1)
	{
		j = i + 1;
		while (j < stack_a_len)
		{
			if (copy[i] > copy[j])
				swap(&copy[i], &copy[j]);
			j++;
		}
		i++;
	}
	pivot = copy[stack_a_len / 2];
	free(copy);
	return (pivot);
}

void	divide_stack(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len)
{
	int	i;
	int	pivot;

	pivot = find_pivot(*stack_a, *stack_a_len);
	i = 0;
	while (i < *stack_a_len)
	{
		if (pivot > (*stack_a)[0])
			push_b(stack_b, stack_b_len, stack_a, stack_a_len);
		else
		{
			rotate_a(*stack_a, *stack_a_len);
			i++;
		}
	}
	sort_selection(stack_a, stack_a_len, stack_b, stack_b_len);
	sort_selection_reverse(stack_b, stack_b_len, stack_a, stack_a_len);
	while (*stack_b_len > 0)
		push_a(stack_a, stack_a_len, stack_b, stack_b_len);

	// print_a(*stack_a, *stack_a_len);
	// printf("sorted: %d\n", is_sorted(*stack_a, *stack_a_len));
}
