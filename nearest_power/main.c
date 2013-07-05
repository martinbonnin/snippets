#include <stdlib.h>
#include <stdio.h>

static void _round(unsigned int v) 
{
    int i = 0;
    printf("%d. %08x\n", i++, v);
    v--;
    printf("%d. %08x\n", i++, v);
    v |= v >> 1;
    printf("%d. %08x\n", i++, v);
    v |= v >> 2;
    printf("%d. %08x\n", i++, v);
    v |= v >> 4;
    printf("%d. %08x\n", i++, v);
    v |= v >> 8;
    printf("%d. %08x\n", i++, v);
    v |= v >> 16;
    printf("%d. %08x\n", i++, v);
    v++;
    printf("%d. %08x\n\n\n", i++, v);
}

int main(int argc, char ** argv)
{
    _round(2);
    _round(3);
    _round(14);
    _round(31056);
    _round(13258);
}
