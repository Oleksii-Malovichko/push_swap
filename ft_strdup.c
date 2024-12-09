/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:29:51 by alex              #+#    #+#             */
/*   Updated: 2024/12/09 22:32:19 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*s2;
	int		i;

	len_s1 = 0;
	i = 0;
	while (s1[len_s1] != '\0')
	{
		len_s1++;
	}
	s2 = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}
	while (i < len_s1)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

void	just_free(int **stack_a, int **stack_b, char **temp)
{
	free(*stack_a);
	*stack_a = NULL;
	free(*stack_b);
	*stack_b = NULL;
	free(*temp);
	*temp = NULL;
}
