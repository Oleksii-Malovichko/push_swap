/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:56:16 by alex              #+#    #+#             */
/*   Updated: 2024/12/02 16:07:32 by alex             ###   ########.fr       */
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
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
		break ;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num > INT_MAX)
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
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

int	get_nums(int **stack_a, char *args)
{
	char	*temp;
	int		len;
	int		i_end;
	
	len = get_len_stack(args);
	*stack_a = malloc(sizeof(int) * (len));
	if (!*stack_a)
	{
		printf("Memory error1\n");
		return (ft_error_exit());
	}
	len = 0;
	temp = get_num(args, &i_end);
	if (!temp)
	{
		printf("Memory error1\n");
		return (ft_error_exit());
	}
	while (temp)
	{
		(*stack_a)[len] = ft_atoi(temp);
		free(temp);
		temp = get_num(args, &i_end);
		len++;
	}
	return (len);
}

int check_chars(char *nums)
{
	int	i;
	int	flag;
	int	wait_space;

	i = 0;
	wait_space = 0;
	flag = 0;
	while (nums[i] != '\0')
	{
		if (nums[i] >= '0' && nums[i] <= '9')
			wait_space = 1;
		if (nums[i] == ' ')
			wait_space = 0;
		if (nums[i] < '0' || nums[i] > '9')
		{
			if (nums[i] == '-' && nums[i + 1] >= '0' && nums[i + 1] <= '9')
			{
				flag = 1;
				i++;
			}
			if (nums[i] != ' ' && flag == 0)
				return (0);
			if (wait_space == 1)
				return (0);
			flag = 0;
		}
		i++;
	}
	return (1);
}

char	*ft_strncpy(char *args, int i_start, int i_end)
{
	char	*temp;
	int		i;

	if (i_end <= i_start)
		return (NULL);
	temp = malloc(sizeof(char) * ((i_end - i_start) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i_start < i_end)
	{
		temp[i] = args[i_start];
		i++;
		i_start++;
	}
	temp[i] = '\0';
	return (temp);
}
