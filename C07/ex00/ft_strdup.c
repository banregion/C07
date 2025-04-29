#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
    int i;
    char *dest;

	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
int main()
{
	char *original = "Hello, world!";
	char *copy = ft_strdup(original);

	if (copy != NULL)
	{
		printf("Original: %s\n", original);
		printf("Copy: %s\n", copy);
		free(copy); // Don't forget to free allocated memory
	}
	else
	{
		printf("Memory allocation failed.\n");
	}

	return 0;
}