#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int c = 0;
	if (argc == 3)
	{
			while(argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					i++;
					c++;
					if (c == ft_strlen(argv[1]))
					{
						write(1, argv[1], c);
					}
				}
				j++;
			}
	}
	write(1, "\n", 1);
}