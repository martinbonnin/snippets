#include <stdio.h>
//#include "g.h"

extern inline int g(void) {
    return 4;
}

int main (int argc, unsigned char argv[]) 
{
    printf("g is %d\n", g());
}


