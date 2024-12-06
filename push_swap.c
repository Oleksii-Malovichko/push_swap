/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omalovic <omalovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:48 by alex              #+#    #+#             */
/*   Updated: 2024/12/06 15:02:39 by omalovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int	*stack_a, int stack_a_len)
{
	int	i;

	i = 0;
	while (i < (stack_a_len - 1))
	{
		if (stack_a[i] > stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int *stack_a, int len)
{
	int	i_main;
	int	i_el;

	i_main = 0;
	while (i_main < len)
	{
		i_el = i_main + 1;
		while (i_el < len)
		{
			if (stack_a[i_main] == stack_a[i_el])
				return (0);
			i_el++;
		}
		i_main++;
	}
	return (1);
}

char	*get_items(int n, char **args, char *result)
{
	int	q_elem;
	int	q_ch;
	int	counter;

	q_elem = 1;
	counter = 0;
	while (q_elem < n)
	{
		q_ch = 0;
		while (args[q_elem][q_ch] != '\0')
		{
			result[counter] = args[q_elem][q_ch];
			counter++;
			q_ch++;
		}
		if (q_elem < n - 1)
		{
			result[counter] = ' ';
			counter++;
		}
		q_elem++;
	}
	result[counter] = '\0';
	return (result);
}

char	*ft_myjoin(int n, char **args)
{
	int		counter;
	int		q_elem;
	int		q_ch;
	char	*result;

	counter = 0;
	q_elem = 1;
	while (q_elem < n)
	{
		q_ch = 0;
		while (args[q_elem][q_ch] != '\0')
		{
			q_ch++;
			counter++;
		}
		if (q_elem < n - 1)
			counter++;
		q_elem++;
	}
	result = malloc(sizeof(char) * (counter + 1));
	if (!result)
		return (NULL);
	return (get_items(n, args, result));
}

int	main(int n, char **args)
{
	int		*stack_a;
	int		*stack_b;
	char	*temp;
	int		stack_a_len;
	int		stack_b_len;

	stack_a = NULL;
	stack_b = NULL;
	stack_b_len = 0;
	temp = args[1];
	if (n == 1)
		return (1);
	if (n > 2)
		temp = ft_myjoin(n, args);
	if (!check_chars(temp))
		return (ft_error());
	stack_a_len = get_nums(&stack_a, temp);
	if (!check_duplicates(stack_a, stack_a_len))
		return (ft_error());
	if (!is_sorted(stack_a, stack_a_len))
		divide_four(&stack_a, &stack_a_len, &stack_b, &stack_b_len);
}
