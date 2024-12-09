/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:28:55 by alex              #+#    #+#             */
/*   Updated: 2024/12/09 22:00:57 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(int **stack, int *stack_len)
{
    int i;
    int max;
    int max_bits;

	i = 0;
    max = (*stack)[0];
    max_bits = 0;
	while (i < *stack_len)
	{
		if ((*stack)[i] > max)
            max = (*stack)[i];
		i++;
	}
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void radix_sort(int **stack_a, int *stack_a_len, int **stack_b, int *stack_b_len)
{
    int i;
	int	j;
    int size;
    int max_bits;

	i = 0;
	size = *stack_a_len;
	max_bits = get_max_bits(stack_a, stack_a_len);
    while (i < max_bits)
    {
        j = 0;
        while (j++ < size)
        {
            if ((((*stack_a)[j] >> i) & 1) == 1)
                rotate_a(*stack_a, *stack_a_len);
            else
                push_b(stack_b, stack_b_len, stack_a, stack_a_len);
        }
        while (*stack_b_len != 0)
            push_a(stack_a, stack_a_len, stack_b, stack_b_len);
		i++;
    }
}
