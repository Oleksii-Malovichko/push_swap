/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:53:11 by omalovic          #+#    #+#             */
/*   Updated: 2024/12/09 22:26:46 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	unsigned long		num;
	int					sign;
	size_t				i;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num > 2147483647 && sign == 1)
			return (ft_error_exit());
		if (num > 2147483648 && sign == -1)
			return (ft_error_exit());
		i++;
	}
	return ((int)(num * sign));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_num(char *args, int *i_end)
{
	int		i_start;
	char	*temp;

	if (*i_end >= ft_strlen(args))
	{
		*i_end = 0;
		return (NULL);
	}
	i_start = *i_end;
	while (args[i_start] == ' ' || (args[i_start] >= 9 && args[i_start] <= 13))
		i_start++;
	*i_end = i_start;
	while ((args[*i_end] >= '0' && args[*i_end] <= '9') || args[*i_end] == '-')
		(*i_end)++;
	if (*i_end > i_start)
	{
		temp = ft_strncpy(args, i_start, *i_end);
		if (!temp)
			exit(EXIT_FAILURE);
		return (temp);
	}
	return (NULL);
}

int	get_len_stack(char *args)
{
	char	*temp;
	int		len;
	int		i_end;

	i_end = 0;
	len = 0;
	temp = get_num(args, &i_end);
	while (temp)
	{
		len++;
		free(temp);
		temp = get_num(args, &i_end);
	}
	return (len);
}

int	get_nums(int **stack_a, char **args)
{
	char	*temp;
	int		len;
	int		i_end;

	i_end = 0;
	len = get_len_stack(*args);
	*stack_a = malloc(sizeof(int) * (len));
	if (!*stack_a)
		return (ft_error_exit());
	len = 0;
	temp = get_num(*args, &i_end);
	if (!temp)
		return (ft_error_exit());
	while (temp)
	{
		(*stack_a)[len] = ft_atoi(temp);
		free(temp);
		temp = get_num(*args, &i_end);
		len++;
	}
	return (len);
}
