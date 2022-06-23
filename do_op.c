#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	int a;
	int b;
	int c;
	if (argc == 4)
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		if (argv[2][0] == '+')
		{
			c = a + b;
			printf("%d\n", c);
		}
		if (argv[2][0] == '-')
		{
			c = a - b;
			printf("%d\n", c);
		}
		if (argv[2][0] == '*')
		{
			c = a * b;
			printf("%d\n", c);
		}
		if (argv[2][0] == '/')
		{
			c = a / b;
			printf("%d\n", c);
		}
		if (argv[2][0] == '%')
		{
			c = a % b;
			printf("%d\n", c);
		}
	}
	else
		write(1, "\n", 1);
}