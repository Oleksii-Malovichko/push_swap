/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:48 by alex              #+#    #+#             */
/*   Updated: 2024/12/02 16:08:06 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
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
	int	counter;
	int	q_elem;
	int	q_ch;
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

int main(int n, char **args)
{
	static int	*stack_a = NULL;
	static int	*stack_b = NULL;
	char		*temp;
	int	stack_a_len;

	temp = args[1];
	if (n == 1)
	{
		printf("Only one arg\n");
		return (ft_error());
	}
	if (n > 2)
		temp = ft_myjoin(n, args);
	if (!check_chars(temp))
	{
		printf("smth wrong with chars\n");
		return (ft_error());
	}
	stack_a_len = get_nums(&stack_a, temp);
	if (!check_duplicates(stack_a, stack_a_len))
	{
		printf("Duplicates!\n");
		return (ft_error());
	}
	for (int i = 0; i < stack_a_len; i++)
		printf("%d\n", stack_a[i]);
}