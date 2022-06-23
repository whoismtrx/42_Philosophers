#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int tab[128] = {0};
	if (argc == 3)
	{
		while(argv[1][i])
		{
			j = 0;
			while(argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && tab[argv[1][i]] == 0)
				{
					write(1, &argv[1][i], 1);
					tab[argv[1][i]] = 1;
					break;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

