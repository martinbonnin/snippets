#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(int argc, char *argv[]) 
{
	const char *iv_str="IV=0x01234567890123456789012345678901";
	char iv_bin[16];

	iv_bin[0]=atoi(iv_str + 5);

	printf("iv_bin[0]=%02x atoi(iv_str + 5)=%d LONG_MAX=%ld\n", iv_bin[0], atoi(iv_str + 5), LONG_MAX);

	return 0;
	
}
