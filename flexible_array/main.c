#include <stdio.h>

#include <stdint.h>
struct a_str {
    int toto;
    int32_t array[];
};

struct b_str {
    int toto;
};

int main(int argc, char **argv)
{
    printf("too" "a: %lu, b: %lu\n", sizeof(struct a_str), sizeof(struct b_str));
    return 0;
}

