#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) 
{
	int r =  2 * 1024 * 1000 - 2000;

	printf("r=%d, stack at %p\n", r, &r);

	if (1) {
		char a[r + 1];
		memset(a, 0xad, r);
		
	}
	return 0;
}

