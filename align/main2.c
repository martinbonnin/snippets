#include <stdio.h>
#include <stdint.h>

static const uint8_t pattern[] = {0x00, 0x01, 0x02, 0x04, 0x08};

int main(int argc, char **argv) 
{
    uint32_t *p = (uint32_t *)(pattern + 1);
    uint32_t toto = 0x00000000;

    printf("toto is     0x%08x\n", toto); 
    printf("accessing address %p\n", p);

    toto ^= *p;

    printf("toto is now 0x%08x\n", toto);
}
