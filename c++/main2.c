#include <stdio.h>


struct my_struct {
	int a;
	int b;
};

int main (int argc, char *argv[])
{
	struct my_struct s;
	s.a = 1;
	s.b = 2;

#ifdef __cplusplus
	printf("C++ %d-%d\n", s.a, s.b);
#else
	printf("C   %d-%d\n", s.a, s.b);
#endif

	return 0;
}
