#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{

int i;
int *tab;

	if(min >= max)
	{
		*range = NULL;
		return 0;
	}

	tab = (int *)malloc (sizeof(int) * (max - min));
	if(tab == NULL)
	{
	*range = NULL;
	return -1;
	}

	i = 0;
	while (min < max)
	{
	tab[i] = min;
	i++;
	min++;
	}
	*range = tab;
	return i;
	
}

int main(void)
{
    int *array;
    int size;
    int i;

    size = ft_ultimate_range(&array, 5, 10);

    if (size > 0)
    {
        for (i = 0; i < size; i++)
            printf("%d ", array[i]);
        free(array);
    }
    else
        printf("Boş dizi oluşturuldu.\n");

    return 0;
}
