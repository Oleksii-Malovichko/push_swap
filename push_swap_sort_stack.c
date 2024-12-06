/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:13:12 by alex              #+#    #+#             */
/*   Updated: 2024/12/06 16:32:05 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

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

void	divide_four(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len)
{
	int	pivot;
	int	i;
	int	*helper;
	int	helper_len;

	helper = NULL;
	helper_len = 0;
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
	divide_sort(stack_a, stack_a_len, &helper, &helper_len);
	free(helper);
	helper = NULL;
	helper_len = 0;
	divide_sort_reverse(stack_b, stack_b_len, &helper, &helper_len);
	while (helper_len > 0)
		push_a(stack_a, stack_a_len, &helper, &helper_len);
	print_a(*stack_a, *stack_a_len);
	printf("is sorted: %d\n", is_sorted(*stack_a, *stack_a_len));
}
