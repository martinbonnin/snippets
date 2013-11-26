#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint8_t clip(int a) 
{
    if (a&(~0xFF)) return (-a)>>31;
    else           return a;
}

int main(int argc, char **argv) 
{
    int a;
    if (argc < 2) {
        printf("%s [number to clip]\n", argv[0]);
        return 1;
    }
    
    a = atoi(argv[1]);
    printf("(-a)=%08x\n", -a);
    printf("a=%d (-a)>>31=%d clip(a)=%d\n", a, (-a)>>31, clip(a));
    return 0;
}
