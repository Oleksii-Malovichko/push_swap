/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_stack3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:22:40 by omalovic          #+#    #+#             */
/*   Updated: 2024/12/06 16:32:09 by omalovic         ###   ########.fr       */
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
