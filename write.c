#include <unistd.h>

int main(void)
{
	int x[1] = {78};

	write(1, &x, sizeof(int));
}
