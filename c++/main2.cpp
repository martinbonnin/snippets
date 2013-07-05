#include <stdio.h>

#pragma GCC diagnostic ignored "-Wshadow"

struct my_struct {
	int a;
	int b;
	my_struct();
};

my_struct::my_struct(void)
{
	printf("constructor\n");
}

#if 1
struct my_struct *my_struct(void)
{
	printf("standard function\n");
	return NULL;
}
#endif

int main (int argc, char *argv[])
{
	struct my_struct s;
	s.a = 1;
	s.b = 2;

	printf("%d-%d\n", s.a, s.b);

	return 0;
}
