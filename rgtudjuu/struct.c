#include <stdio.h>

struct foo {
	char a;
	char *b;
} __attribute__ ((packed));

int main(int argc, char **argv)
{
	printf("size: %u\n", sizeof(struct foo));
}

