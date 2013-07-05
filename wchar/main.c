#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint16_t toto[] = L"toto";

int main(int argc, char* argv[])
{
	int i;
	for (i = 0; i <( sizeof(toto) / sizeof(wchar_t)); i++) {
		printf("%c", toto[i]);
	}

	return 0;
}
