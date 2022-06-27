#include <stdlib.h>
#include <stdio.h>

int    *ft_range(int min, int max)
{
    int    size;
    int    *ret;
    int    i;

    size = max - min;
    if (min >= max)
        return (0);
    ret = (int *)malloc(sizeof(int) * size);
    i = 0;
    while(min < max)
    {
        ret[i] = min;
        min++;
        i++;
    }
    return (ret);
}

int ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	i = 0;
	if (!range)
		return (-1);
	*range = ft_range(min, max);
	return (size);
}

int main()
{
    int **ret = NULL;
	int size = ft_ultimate_range(ret, 0, 10);
    printf("%d\n", size);
	for(int i = 0; i < 10; i++)
		printf("%d ", ret[0][i]);
}