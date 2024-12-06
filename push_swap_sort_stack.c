/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:13:12 by alex              #+#    #+#             */
/*   Updated: 2024/12/06 16:04:40 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_strcpy(int *stack_a, int stack_a_len)
{
	int	*copy;
	int	i;

	copy = malloc(stack_a_len * sizeof(int));
	if (!copy)
		return (ft_error(), NULL);
	i = 0;
	while (i < stack_a_len)
	{
		copy[i] = stack_a[i];
		i++;
	}
	return (copy);
}

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

void	sort_selection(int **stack_a, int *stack_a_len, int flag)
{
	int	smallest_index;
	int	*stack_b = NULL;
	int	stack_b_len = 0;

	if (flag == 0)
	{
		while (*stack_a_len > 3)
		{
			smallest_index = find_smallest(*stack_a, *stack_a_len);
			get_item(stack_a, stack_a_len, smallest_index);
			push_b(&stack_b, &stack_b_len, stack_a, stack_a_len);
		}
		sort_three(stack_a, stack_a_len);
	}
	else
	{
		while (*stack_a_len > 0)
		{
			smallest_index = find_biggest(*stack_a, *stack_a_len);
			get_item(stack_a, stack_a_len, smallest_index);
			push_b(&stack_b, &stack_b_len, stack_a, stack_a_len);
		}
	}
	while (stack_b_len > 0)
		push_a(stack_a, stack_a_len, &stack_b, &stack_b_len);
	free(stack_b);
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
	sort_selection(stack_a, stack_a_len, 0);
	sort_selection(stack_b, stack_b_len, 1);
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
	sort_selection(stack_a, stack_a_len, 0);
	sort_selection(stack_b, stack_b_len, 1);
	while (*stack_a_len > 0)
		push_b(stack_b, stack_b_len, stack_a, stack_a_len);
}

void	divide_four(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len)
{
	int	pivot;
	int	i;
	int	*helper = NULL;
	int	helper_len = 0;

	if (*stack_a_len < 10)
		return (sort_selection(stack_a, stack_a_len, 0));
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
