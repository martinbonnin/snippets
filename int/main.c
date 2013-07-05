#include <stdlib.h>
#include <stdio.h>


int main (int argc, char **argv)
{
    int a, b;
    long int c;
    printf("sizeof(long int) is %u\n", sizeof(c));

     if (argc < 3) {
        printf("%s num1 num2\n", argv[0]);
        exit(1);
    }
    
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    
    printf("a: %08x %d\n", a, a);
    printf("b: %08x %d\n", b, b);

    printf("a + b: %08x %d >= 0 %s\n", a + b, a + b, (a + b) > 0 ? "Y" : "N");
    printf("a - b: %08x %d >= 0 %s\n", a - b, a - b, (a - b) > 0 ? "Y" : "N");

    return 1;
}
