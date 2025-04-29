#include <stdlib.h>
#include <stdio.h>
	
int ft_strlen(char *str)
{
	int len = 0;
	while(str[len])
		len++;
	return len;	
}

int total_lengt(int size,char **strs,char *sep)
{
	int total;
	int i;

	total = 0;
	i = 0;
	while(i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += (size -1) * ft_strlen(sep);
	return total;
}
void	fill_joined_string(char *tab, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			tab[k++] = strs[i][j];
		if (i < size - 1)
		{
			j = -1;
			while (sep[++j])
				tab[k++] = sep[j];
		}
	}
	tab[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		len;

	if (size <= 0)
	{
		tab = (char *)malloc(sizeof(char));
		if (!tab)
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	len = total_length(size, strs, sep);
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	fill_joined_string(tab, strs, sep, size);
	return (tab);
}
/*char *ft_strjoin(int size, char **strs, char *sep)
{
	int k;
	int i;
	int j;
	char *tab;
	int len;
			
	len = total_lengt(size,strs,sep);
	if (size <= 0)
	{
    	tab = (char *)malloc(sizeof(char));
    	if (!tab)
        	return NULL;
    	tab[0] = '\0';
    	return tab;
	}
	tab = (char *)malloc (sizeof(char) * (len + 1));
	if (!tab)
        	return NULL;
	i = 0;
	k = 0;
	while(i < size)
	{
		j = 0;
		while(strs[i][j])
			tab[k++] = strs[i][j++];
		if (i < size -1)
		{
			j = 0;
			while(sep[j])
				tab[k++] = sep[j++];
		}
		i++;
	}
	tab[k] = '\0';
	return tab;
}
/*int main()
{
    char *words[] = {"hello", "world", "42"};
    char *sep = "-";
    char *joined = ft_strjoin(3, words, sep);
    printf("%s\n", joined);
    free(joined);
    return 0;
}*/
int	main(void)
{
	char	*arr[] = {"Hello", "42", "Network", "Cadet"};
	char	*sep = "-";
	char	*result;
	int		size;

	size = 4;
	result = ft_strjoin(size, arr, sep);
	if (result)
	{
		printf("Result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}
