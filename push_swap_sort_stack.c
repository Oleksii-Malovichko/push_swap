/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:13:12 by alex              #+#    #+#             */
/*   Updated: 2024/12/04 13:28:36 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(int **stack_a, int *stack_a_len)
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
	{
		push_a(stack_a, stack_a_len, stack_b, stack_b_len);
	}
}

// int find_pivot(int *stack_a, int stack_a_len)
// {
//     int *copy = malloc(stack_a_len * sizeof(int));
//     int i;

//     // Копируем элементы стека в новый массив
//     for (i = 0; i < stack_a_len; i++)
//         copy[i] = stack_a[i];

//     // Сортируем копию массива
//     for (i = 0; i < stack_a_len - 1; i++)
//     {
//         int j;
//         for (j = i + 1; j < stack_a_len; j++)
//         {
//             if (copy[i] > copy[j])
//             {
//                 int temp = copy[i];
//                 copy[i] = copy[j];
//                 copy[j] = temp;
//             }
//         }
//     }
//     // Возвращаем медиану (средний элемент отсортированного массива)
//     int pivot = copy[stack_a_len / 2];
//     free(copy);  // Освобождаем память
//     return pivot;
// }

// void	quick_sort(int **stack_a, int *stack_a_len, int **stack_b, int *stack_b_len)
// {
// 	int	pivot;
// 	int	i;

// 	while (*stack_a_len > 3)
// 	{
// 		pivot = find_pivot(*stack_a, *stack_a_len);
// 		i = 0;
// 		while (i < *stack_a_len)
// 		{
// 			if (pivot > (*stack_a)[0])
// 			{
// 				push_b(stack_b, stack_b_len, stack_a, stack_a_len);
// 			}
// 			else
// 			{
// 				rotate_a(*stack_a, *stack_a_len);
// 			}
// 			i++;
// 		}
// 	}
// 	sort_three(stack_a, stack_a_len);
// 	while (*stack_b_len > 0)
// 	{
// 		push_a(stack_a, stack_a_len, stack_b, stack_b_len);
// 	}
// }
