// #include <stdio.h>
// #include <stdlib.h>

// void	push_swap(int *a, int *b)
// {
// 	int temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// void	quick_sort(int **stack_a, int *len_a, int **stack_b, int *len_b)
// {
// 	int	pivot = (*stack_a)[0];
// 	int	i;

// 	i = 1;
// 	while (i < *len_a)
// 	{
// 		if (pivot > (*stack_a)[i])
// 		{
// 			push_b(stack_a, i, stack_b); // элемент из стека a в стек b
// 			(*len_a)--;
// 			(*len_b)++;
// 		}
// 	}
// }

// int main()
// {
// 	int	stack_a[] = {4, 22, 1, 9, 0};
// 	int len = sizeof(stack_a) / sizeof(stack_a[0]);
// 	int	stack_b[len];
	
// 	for (int i = 0; i < len; i++)
// 		printf("%d\n", stack_a[i]);
// }