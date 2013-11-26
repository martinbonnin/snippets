#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

uint8_t array[64];

void add_dc(uint8_t *dest, int linesize, int16_t *block);

static void _dump_array(const char *label)
{
    int i; 
    int j;
    printf("%s", label);
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("0x%02x ", array[8*i + j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int16_t _block = 72;
    _dump_array("before\n");
    vc1_inv_trans_8x8_dc_c_neon(array, 8, &_block);
    _dump_array("after\n");

    return 0;
}
