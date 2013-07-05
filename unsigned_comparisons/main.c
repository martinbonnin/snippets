#include <stdio.h>

int main(int argc, char **argv)
{
	int a = -1;
	unsigned int b = 2;

	printf("a(%d) is %s than b(%u)\n", a, a < (int)b ? "less" : "more",  b);

	return 0;
}

