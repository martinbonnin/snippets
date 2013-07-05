#include <stdio.h>
#include <stdint.h>

static const uint8_t pattern[] = {0x00, 0x01, 0x02, 0x04, 0x08};

int main(int argc, char **argv) 
{
    struct __attribute__((packed)) unaligned_data32 {
        uint32_t data[1];
    };
    struct unaligned_data32 *p = (void *)(pattern + 1);
    uint32_t toto = 0x00000000;

    printf("toto is     0x%08x\n", toto);

    toto ^= p->data[0];

    printf("toto is now 0x%08x\n", toto);
}
