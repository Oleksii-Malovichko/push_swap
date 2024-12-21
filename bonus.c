/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 03:12:51 by alex              #+#    #+#             */
/*   Updated: 2024/12/21 04:00:21 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line/get_next_line.h"

void	create_db(s_mylist **data_base, char **temp)
{
	
}// cc *.c ./get_next_line/* -o bonus.o 

int main(int n, char **args)
{
	int		*stack_a;
	int		stack_a_len;
	char	*temp;
	s_mylist data_base = {0};

	if (n == 1)
		return (1);
	stack_a = NULL;
	if (n == 2)
		temp = ft_strdup(args[1]);
	if (n > 2)
		temp = ft_myjoin(n, args);
	if (!temp)
		return (free(stack_a), ft_error());
	stack_a_len = get_nums(&stack_a, &temp);
	free(temp);
	while ((temp = get_next_line(0)) != "(null)")
		create_db(&data_base, &temp);
	if (!is_sorted(stack_a, stack_a_len))
		return (free(stack_a), free(temp), write(1,"KO\n", 3), 1);
	return (free(stack_a), free(temp), write(1,"OK\n", 3), 0);
}