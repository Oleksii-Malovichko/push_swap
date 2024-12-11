/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:22:40 by omalovic          #+#    #+#             */
/*   Updated: 2024/12/11 19:42:24 by alex             ###   ########.fr       */
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

void	free_stacks(int **stack_a, int **stack_b, char **temp)
{
	if (*stack_a != NULL)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	if (*stack_b != NULL)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	if (*temp != NULL)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
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
