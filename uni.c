#include <unistd.h>

int main(int argc, char **argv)
{
	static int d[256];
	int i = 1, j;
	if (argc == 3)
	{
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!d[(unsigned char)argv[i][j]])
				{
					d[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}