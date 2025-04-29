#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max)
{
	int *range;
	int i;
	int size;

	if(min >= max)
		return NULL;

	size = max - min;		
	range = (int *)malloc (sizeof(int) * size);
	if(!range)
		return NULL;

	i = 0;
	while(min < max)
	{
		range[i] = min;
		min++;
		i++;
	}	
	return range;
}
int main()
{
    int *arr;
    int i;

    arr = ft_range(2, 7); // 3,4,5,6 oluşturur

    if (arr)
    {
        for (i = 1; i < 5; i++)
            printf("%d ", arr[i]);
        free(arr); // Unutma: malloc kullandığın için free ile bellek boşaltılmalı
    }

    return 0;
}
// This code defines a function `ft_range` that creates an array of integers from `min` to `max - 1`.
// It allocates memory for the array and fills it with the appropriate values.
// The `main` function demonstrates how to use `ft_range` and prints the resulting array.
// The code also includes error handling for memory allocation failure.
// The `ft_range` function returns a pointer to the allocated array, or NULL if the allocation fails or if `min` is greater than or equal to `max`.
// The `main` function tests the `ft_range` function by creating an array from 5 to 9 and printing the values.		