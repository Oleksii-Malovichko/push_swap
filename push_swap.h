/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:50:57 by alex              #+#    #+#             */
/*   Updated: 2024/12/02 15:37:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
char	**ft_split(char const *s, char c);
int	ft_atoi(char *str);
int	ft_error_exit(void);
int	get_nums(int **stack_a, char *args);
int check_chars(char *nums);
char	*ft_strncpy(char *args, int i_start, int i_end);

#endif