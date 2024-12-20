/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:57 by alex              #+#    #+#             */
/*   Updated: 2024/12/21 03:51:34 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

void	divide_stack(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len);
char	*ft_strdup(const char *s1);
void	swap(int *a, int *b);
void	free_stacks(int **stack_a, int **stack_b, char **temp);
char	**ft_split(char const *s, char c);
int		ft_error(void);
int		ft_atoi(char *str, int *flag);
int		ft_error_exit(void);
int		get_nums(int **stack_a, char **args);
int		check_chars(char *nums);
char	*ft_strncpy(char *args, int i_start, int i_end);
void	swap_a(int **stack_a, int stack_a_len);
void	swap_b(int **stack_b, int stack_b_len);
void	swap_ss(int **stack_a, int stack_a_len, int **stack_b, int stack_b_len);
int		*pop_item(int **stack_a, int stack_a_len);
int		*push_item(int **stack_a, int stack_a_len, int new);
void	push_a(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len);
void	push_b(int **stack_b, int *stack_b_len,
			int **stack_a, int *stack_a_len);
void	print_a(int *stack_a, int stack_a_len);
void	print_b(int *stack_a, int stack_a_len);
void	rotate_a(int *stack_a, int stack_a_len);
void	rotate_b(int *stack_b, int stack_b_len);
void	rotate_rr(int *stack_a, int stack_a_len, int *stack_b, int stack_b_len);
void	reverse_rotate_a(int *stack_a, int stack_a_len);
void	reverse_rotate_b(int *stack_b, int stack_b_len);
void	reverse_rotate_rr(int *stack_a, int stack_a_len,
			int *stack_b, int stack_b_len);
int		is_sorted(int	*stack_a, int stack_a_len);
void	get_item1(int **stack_a, int *stack_a_len, int smallest_index);
void	get_item2(int **stack_b, int *stack_b_len, int smallest_index);
void	sort_selection(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len);
void	sort_selection_reverse(int **stack_a, int *stack_a_len,
			int **stack_b, int *stack_b_len);
int		*ft_strcpy(const int *stack_a, int stack_a_len);
void	just_free(int **stack_a, int **stack_b, char **temp);
int		find_smallest(int *stack_a, int stack_a_len);
int		find_biggest(int *stack_a, int stack_a_len);
char	*get_items(int n, char **args, char *result);
char	*ft_myjoin(int n, char **args);
int	ft_strlen(char *str);

typedef struct s_mylist
{
	char *data;
	s_mylist *next;
} s_mylist;


#endif