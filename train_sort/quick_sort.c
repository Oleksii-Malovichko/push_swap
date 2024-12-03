#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high, int temp[])
{
    int pivot = arr[high];
    int i = low - 1;
    int j = low;
    int k = 0;

    while (j < high)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i + 1], &arr[high]);

    while (low < high)
    {
        if (arr[low] <= pivot)
        {
            temp[k] = arr[low];
            low++;
        }
        else
        {
            temp[k] = arr[high];
            high--;
        }
        k++;
    }

    return (i + 1);
}

void quick_sort(int arr[], int low, int high, int temp[])
{
	int pivot_index;
	if (low < high)
	{
		pivot_index = partition(arr, low, high, temp);
		quick_sort(arr, low, pivot_index - 1, temp);
		quick_sort(arr, pivot_index + 1, high, temp);
	}
}

int main()
{
	int	arr[] = {38, 27, 43, 3, 9, 82, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
    int *temp = malloc(sizeof(int) * n);

	quick_sort(arr, 0, n - 1, temp);

    int i = 0;
    while (i < n) {
        printf("%d ", arr[i]);
        i++;
    }

    free(temp);
}


// void	quick_sort(int **stack_a, int *stack_a_len, int **stack_b, int *stack_b_len)
// {
// 	int	pivot;
// 	int	i;
// 	int	rotated;

// 	rotated = 0;
// 	i = 0;
// 	pivot = (*stack_a)[0];
// 	if (*stack_a_len <= 1)
// 		return ;
// 	if (is_sorted(*stack_a, *stack_a_len))
// 		return ;
// 	while (i < *stack_a_len)
// 	{
// 		if (pivot > (*stack_a)[0])
// 		{
// 			push_b(stack_b, stack_b_len, stack_a, stack_a_len);
// 		}
// 		else
// 		{
// 			rotate_a(*stack_a, *stack_a_len);
// 			i++;
// 		}
// 	}
// 	if (*stack_b_len > 0)
// 		quick_sort(stack_b, stack_b_len, stack_a, stack_a_len); 
// 	// quick_sort(stack_a, stack_a_len, stack_b, stack_b_len);
	
// 	print_a(*stack_a, *stack_a_len);
// 	print_b(*stack_b, *stack_b_len);
// 	while (*stack_b_len > 0)
// 	{
// 		push_a(stack_a, stack_a_len, stack_b, stack_b_len);
// 	}
// 	if (*stack_a_len <= 3)
// 	{
// 		three_sort(stack_a, stack_a_len);
// 	}
// 	if (*stack_b_len <= 3)
// 	{
// 		three_sort(stack_b, stack_b_len);
// 	}
// }