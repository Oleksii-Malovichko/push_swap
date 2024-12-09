/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:13:12 by alex              #+#    #+#             */
/*   Updated: 2024/12/07 15:04:36 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(int *stack_a, int stack_a_len)
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

void	divide_sort(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len)
{
	int	pivot;
	int	i;

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
	sort_selection(stack_a, stack_a_len);
	sort_selection_reverse(stack_b, stack_b_len);
	while (*stack_b_len > 0)
		push_a(stack_a, stack_a_len, stack_b, stack_b_len);
}

void	divide_sort_reverse(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len)
{
	int	pivot;
	int	i;

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
	sort_selection(stack_a, stack_a_len);
	sort_selection_reverse(stack_b, stack_b_len);
	while (*stack_a_len > 0)
		push_b(stack_b, stack_b_len, stack_a, stack_a_len);
}

void	transition_to_dividing(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len)
{
	int	*helper;
	int	helper_len;

	helper = NULL;
	helper_len = 0;
	divide_sort(stack_a, stack_a_len, &helper, &helper_len);
	free(helper);
	helper = NULL;
	helper_len = 0;
	divide_sort_reverse(stack_b, stack_b_len, &helper, &helper_len);
	while (helper_len > 0)
		push_a(stack_a, stack_a_len, &helper, &helper_len);
}

void	divide_four(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len)
{
	int	pivot;
	int	i;

	if (*stack_a_len < 10)
		return (sort_selection(stack_a, stack_a_len));
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
	transition_to_dividing(stack_a, stack_a_len, stack_b, stack_b_len);
}

// print_a(*stack_a, *stack_a_len);
// printf("is sorted: %d\n", is_sorted(*stack_a, *stack_a_len));