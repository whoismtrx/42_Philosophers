#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int tab[128] = {0};
	if (argc == 3)
	{
		while(argv[1][i])
		{
			if (tab[argv[1][i]] == 0)
			{
				write(1, &argv[1][i], 1);
				tab[argv[1][i]] = 1;
			}
			i++;
		}
		i = 0;
		while(argv[2][i])
		{
			if (tab[argv[2][i]] == 0)
			{
				write(1, &argv[2][i], 1);
				tab[argv[2][i]] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}