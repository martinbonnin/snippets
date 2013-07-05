#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char *a;
    long long s;

//printf("--1 %%5 %d\n", -1 % 5);
    
    if (argc < 1) {
        printf("usage: %s [total memory]\n", argv[0]);
        exit(1);
    }

    s = atoll(argv[1]);

    printf("allocate %lld bytes\n", s);

    a = malloc(s);

    if (a == NULL) {
    printf("alloc failed\n");
}

    if (argc > 2) {
        long long m = atoll(argv[2]);
        printf("use %lld bytes\n", m);
        memset(a, 0xda, m);
    }
    
    while(1) {usleep(1000000);};

    return 0;
}

