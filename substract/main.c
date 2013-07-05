#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	uint16_t a, b;

	a = 5;
	b = 0xffff;

	printf("a=%u b=%u a-b=%u\n", a, b, (uint16_t)(a - (uint16_t)b));
	return 0;
}

