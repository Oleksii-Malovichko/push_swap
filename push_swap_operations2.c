/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:22:01 by omalovic          #+#    #+#             */
/*   Updated: 2024/12/06 14:23:20 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_exit(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (1);
}

void	swap_a(int **stack_a, int stack_a_len)
{
	int	temp;

	if (stack_a_len < 2)
		return ;
	temp = (*stack_a)[0];
	(*stack_a)[0] = (*stack_a)[1];
	(*stack_a)[1] = temp;
	write(1, "sa\n", 3);
}

void	swap_b(int **stack_b, int stack_b_len)
{
	int	temp;

	if (stack_b_len < 2)
		return ;
	temp = (*stack_b)[0];
	(*stack_b)[0] = (*stack_b)[1];
	(*stack_b)[1] = temp;
	write(1, "sb\n", 3);
}

void	swap_ss(int **stack_a, int stack_a_len, int **stack_b, int stack_b_len)
{
	swap_a(stack_a, stack_a_len);
	swap_b(stack_b, stack_b_len);
}

int	*pop_item(int **stack_a, int stack_a_len)
{
	int	i;
	int	*temp;

	temp = malloc(sizeof(int) * (stack_a_len - 1));
	if (!temp)
		ft_error_exit();
	i = 0;
	while (i < (stack_a_len - 1))
	{
		temp[i] = (*stack_a)[i + 1];
		i++;
	}
	free(*stack_a);
	*stack_a = NULL;
	return (temp);
}