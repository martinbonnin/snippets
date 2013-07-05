#include <stdio.h>
typedef struct {
	int a;
	int b;
	int c;
} Test;


int main (int argc, char **argv)
{
	Test t;
	int a = 0xdeadbeef;

	t.a = a;
	t.b = 123;
	t.c = 666;

	printf("sizeof(Test): %d\n", (int)sizeof(Test));

	printf("%d - %d - %d\n", t.a, t.b, t.c);

	return 0;
}
