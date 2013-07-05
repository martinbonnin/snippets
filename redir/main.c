#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv)
{
	write(1, "stdout\n", 8);
	write(2, "stderr\n", 8);

	return 0;
}
