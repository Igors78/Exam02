#include <unistd.h>
int main(int argc, char **argv)
{
	static int d[256];
	int i = 0;
	char *s1;
	char *s2;
	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		while (s2[i])
		{
			if (!d[(unsigned char)s2[i]])
			{
				d[(unsigned char)s2[i]] = 1;
				i++;
			}
			while (s1[i])
			{
				if (d[(unsigned char)s1[i]] == 1)
				{
					write(1, &s1[i], 1);
					i++;
				}
				else
				{
					d[(unsigned char)s1[i]] = 2;
					i++;
				}
			}
		}
		write(1, "\n", 1);
		return (0);
	}
}