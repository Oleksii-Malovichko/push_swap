/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:36:08 by alex              #+#    #+#             */
/*   Updated: 2024/12/03 15:40:37 by alex             ###   ########.fr       */
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
	// write(1, "ss\n", 1);
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

int	*push_item(int **stack_a, int stack_a_len, int new)
{
	int	i;
	int	*temp;
	
	temp = malloc(sizeof(int) * (stack_a_len + 1));
	if (!temp)
		ft_error_exit();
	i = 0;
	temp[0] = new;
	while (i < stack_a_len)
	{
		temp[i + 1] = (*stack_a)[i];
		i++;
	}
	free(*stack_a);
	*stack_a = NULL;
	return (temp);
}

void	push_a(int **stack_a, int *stack_a_len, int **stack_b, int *stack_b_len)
{
	int	elem;

	if (*stack_b_len == 0)
		return ;
	elem = (*stack_b)[0];
	*stack_a = push_item(stack_a, *stack_a_len, elem);
	*stack_b = pop_item(stack_b, *stack_b_len);
	(*stack_a_len)++;
	(*stack_b_len)--;
	write(1, "pa\n", 3);
}

void	push_b(int **stack_b, int *stack_b_len, int **stack_a, int *stack_a_len)
{
	int	elem;

	if (*stack_a_len == 0)
		return ;
	elem = (*stack_a)[0];
	*stack_b = push_item(stack_b, *stack_b_len, elem);
	*stack_a = pop_item(stack_a, *stack_a_len);
	(*stack_b_len)++;
	(*stack_a_len)--;
	write(1, "pb\n", 3);
}

void	print_a(int *stack_a, int stack_a_len)
{
	printf("Stack_a:\n");
	for (int i = 0; i < stack_a_len; i++)
		printf("%d ", (stack_a)[i]);
	printf("\n");
}

void	print_b(int *stack_a, int stack_a_len)
{
	printf("Stack_b:\n");
	for (int i = 0; i < stack_a_len; i++)
		printf("%d ", (stack_a)[i]);
	printf("\n");
}

void	rotate_a(int *stack_a, int stack_a_len)
{
	int	first_elem;
	int	i;

	if (stack_a_len <= 1)
		return ;
	first_elem = stack_a[0];
	i = 0;
	while (i < stack_a_len - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[stack_a_len - 1] = first_elem;
	write(1, "ra\n", 3);
}

void	rotate_b(int *stack_b, int stack_b_len)
{
	int	first_elem;
	int	i;

	if (stack_b_len <= 1)
		return ;
	first_elem = stack_b[0];
	i = 0;
	while (i < stack_b_len - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[stack_b_len - 1] = first_elem;
	write(1, "rb\n", 3);
}

void	rotate_rr(int *stack_a, int stack_a_len, int *stack_b, int stack_b_len)
{
	rotate_a(stack_a, stack_a_len);
	rotate_b(stack_b, stack_b_len);	
}

void	reverse_rotate_a(int *stack_a, int stack_a_len)
{
	int last_elem;
	int i;

	if (stack_a_len <= 1)
		return ;
	last_elem = stack_a[stack_a_len - 1];
	i = stack_a_len - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = last_elem;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(int *stack_b, int stack_b_len)
{
	int last_elem;
	int i;

	if (stack_b_len <= 1)
		return ;
	last_elem = stack_b[stack_b_len - 1];
	i = stack_b_len - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = last_elem;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_rr(int *stack_a, int stack_a_len, int *stack_b, int stack_b_len)
{
	reverse_rotate_a(stack_a, stack_a_len);
	reverse_rotate_b(stack_b, stack_b_len);
}

void	get_item(int **stack_a, int *stack_a_len, int index)
{
	int	i;
	int	got_item;

	if (index >= *stack_a_len)
		ft_error_exit();
	got_item = (*stack_a)[index];
	if (index < (*stack_a_len / 2))
	{
		i = 0;
		while (i < index)
		{
			rotate_a(*stack_a, *stack_a_len);
			i++;
		}
	}
	else
	{
		i = (*stack_a_len) - 1;
		while (i >= index)
		{
			reverse_rotate_a(*stack_a, *stack_a_len);
			i--;
		}
	}
}

// int main()
// {
// 	int *stack_a = malloc(sizeof(int) * 7);
// 	stack_a[0] = 1; stack_a[1] = 2; stack_a[2] = 3; stack_a[3] = 4; stack_a[4] = 5; stack_a[5] = 6; stack_a[6] = 7;
// 	int stack_a_len = 7;

// 	int *stack_b = malloc(sizeof(int) * 2);
// 	stack_b[0] = 5; stack_b[1] = 0;
// 	int stack_b_len = 2;
	
// 	print_a(stack_a, stack_a_len);
// 	print_b(stack_b, stack_b_len);

// 	get_item(&stack_a, &stack_a_len, 6);

// 	print_a(stack_a, stack_a_len);
// 	// print_b(stack_b, stack_b_len);
// 	// rotate_rr(stack_a, stack_a_len, stack_b, stack_b_len);
// 	// print_a(stack_a, stack_a_len);
// 	// print_b(stack_b, stack_b_len);

// 	// reverse_rotate_rr(stack_a, stack_a_len, stack_b, stack_b_len);
// 	// print_a(stack_a, stack_a_len);
// 	// print_b(stack_b, stack_b_len);


// }

